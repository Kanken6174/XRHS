#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../Elements/mesh.hpp"
#include <memory>
class OBJLoader {
public:
    std::vector<std::shared_ptr<Mesh>> loadModel(const std::string& path);

private:
    std::string directory;

    std::vector<std::shared_ptr<Mesh>> processNode(aiNode* node, const aiScene* scene);
    std::shared_ptr<Mesh> processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
    unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma);
    std::string processTexturePath(const std::string& hardCodedPath, const std::string& actualDirectoryPath);
};