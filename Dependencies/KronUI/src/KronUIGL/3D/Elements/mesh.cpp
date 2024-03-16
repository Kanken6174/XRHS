#include "mesh.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <utility>
#include <GL/glew.h>
#include <iostream>
#include "../../../../include/logger.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
    : vertices(std::move(vertices)), indices(std::move(indices)), textures(std::move(textures))
{
    //check if mesh has a normal texture for bump mapping and set bool
    for (const auto& texture : textures) {
        if (texture.type == "texture_normal") {
            hasNormals = true;
            break;
        }
    }
}

Mesh::Mesh() = default;

void Mesh::setupMesh(GLuint shaderProgram) {
    
    Logger::getInstance().warn("Setting up mesh "+std::to_string(this->vertices.size()) + " vertices, " + std::to_string(this->indices.size()) + 
    " indices, " + std::to_string(this->textures.size()) + " textures");

    glUseProgram(shaderProgram);

    glBindAttribLocation(shaderProgram, 0, "Position");
    glBindAttribLocation(shaderProgram, 1, "TexCoords");
    glBindAttribLocation(shaderProgram, 2, "Normal");

    glLinkProgram(shaderProgram);

    GLint linkStatus;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
        Logger::getInstance().fatal("Could not link shader program");
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Vertex Positions
    GLint positionIndex = 0;//glGetAttribLocation(shaderProgram, "Position");
    if (positionIndex == -1) {
        Logger::getInstance().fatal("Could not find attribute Position in shader program");
    }
    glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray (positionIndex);
    
    // Vertex Texture Coords
    GLint textureCoordsIndex = 1;//glGetAttribLocation(shaderProgram, "TexCoords");
    if (textureCoordsIndex == -1) {
        Logger::getInstance().fatal("Could not find attribute TexCoords in shader program");
    }
    glVertexAttribPointer(textureCoordsIndex, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    glEnableVertexAttribArray(textureCoordsIndex);

    // Vertex Normals
    GLint normalsIndex = 2;//glGetAttribLocation(shaderProgram, "Normal");
    if(normalsIndex == -1) {
        Logger::getInstance().fatal("Could not find attribute Normal in shader program");
    }
    glVertexAttribPointer(normalsIndex, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    glEnableVertexAttribArray(normalsIndex);

    glBindVertexArray(0);
}