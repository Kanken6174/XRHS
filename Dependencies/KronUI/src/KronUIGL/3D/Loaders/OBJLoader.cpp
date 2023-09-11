#include "./OBJLoader.hpp"
#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#include "./../../../../include/stb_image.h"
#include "./../../../../include/logger.hpp"

std::string findClosestFileMatch(const std::string& target, const std::string& directoryPath) {
    std::filesystem::path targetPath(target);
    std::string targetStem = targetPath.stem().string();
    std::string closestMatch;
    size_t closestMatchScore = 0;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            std::string stem = entry.path().stem().string();
            size_t score = 0;
            for (size_t i = 0; i < std::min(targetStem.size(), stem.size()); ++i) {
                if (targetStem[i] == stem[i]) {
                    score++;
                } else {
                    break;
                }
            }
            if (score > closestMatchScore) {
                closestMatch = entry.path().string();
                closestMatchScore = score;
            }
        }
    }

    return closestMatch;
}

std::vector<std::shared_ptr<Mesh>> OBJLoader::processNode(aiNode* node, const aiScene* scene) {
    std::vector<std::shared_ptr<Mesh>> meshes;
    for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    for (unsigned int i = 0; i < node->mNumChildren; ++i) {
        auto childMeshes = processNode(node->mChildren[i], scene);
        meshes.insert(meshes.end(), childMeshes.begin(), childMeshes.end());
    }
    return meshes;
}

std::vector<std::shared_ptr<Mesh>> OBJLoader::loadModel(const std::string& path) {
    Assimp::Importer importer;
    directory = path.substr(0, path.find_last_of('/'));
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        Logger::getInstance().log(Logger::Level::ERROR, "ASSIMP Error: " + std::string(importer.GetErrorString()));
        return {};
    }
    return processNode(scene->mRootNode, scene);
}

std::shared_ptr<Mesh> OBJLoader::processMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        Vertex vertex;
        vertex.Position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);

        if (mesh->mNormals) {  // If there are normals in the mesh data
            vertex.Normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);
        }

        if (mesh->HasTextureCoords(0)){
            vertex.TexCoords = glm::vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
            Logger::getInstance().log(Logger::Level::INFO, "Mesh has texture coordinates: "+std::to_string(vertex.TexCoords.x)+", "+std::to_string(vertex.TexCoords.y));
        } else {
            Logger::getInstance().log(Logger::Level::WARNING, "Mesh has no texture coordinates");
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);
        }
        vertices.push_back(vertex);
    }
    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; ++j)
            indices.push_back(face.mIndices[j]);
    }

    if(mesh->mMaterialIndex >= 0) {
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

        std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        Logger::getInstance().warn("Mesh diffuse maps: "+std::to_string(diffuseMaps.size()));

        std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
        Logger::getInstance().warn("Mesh specular maps: "+std::to_string(specularMaps.size()));

        std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
        textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

        Logger::getInstance().warn("Mesh normal maps: "+std::to_string(normalMaps.size()));
    }

    return std::make_shared<Mesh>(vertices, indices, textures);
}

std::vector<Texture> OBJLoader::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
{
    std::vector<Texture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        Texture texture;
        texture.id = TextureFromFile(processTexturePath(str.C_Str(), directory).c_str(), directory, false);
        texture.type = typeName;
        texture.path = str;
        textures.push_back(texture);
    }
    return textures;
}

unsigned int OBJLoader::TextureFromFile(const char* path, const std::string& directory, bool gamma)
{
    std::string filename = processTexturePath(path, directory);

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        Logger::getInstance().log(Logger::Level::ERROR, "Texture failed to load at path: " + filename);
        stbi_image_free(data);
    }

    return textureID;
}

std::string OBJLoader::processTexturePath(const std::string& hardCodedPath, const std::string& actualDirectoryPath) {
    std::filesystem::path p(hardCodedPath);
    return actualDirectoryPath + "/textures/" + p.filename().string();
}