#include "mesh.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <utility>
#include <GL/glew.h>
#include <iostream>
#include "../../../../include/logger.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, std::shared_ptr<Transform> transform)
    : vertices(std::move(vertices)), indices(std::move(indices)), textures(std::move(textures)), transform(std::move(transform))
{
    //check if mesh has a normal texture for bump mapping and set bool
    for (const auto& texture : textures) {
        if (texture.type == "texture_normal") {
            hasNormals = true;
            break;
        }
    }
}

glm::mat4 Mesh::getTransformMatrix() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, transform->getPosition());
    model = glm::rotate(model, glm::radians(transform->getEulerAngles().x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->getEulerAngles().y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->getEulerAngles().z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, transform->getScale());
    if(model[0][0] == 0.0f || model[1][1] || 0.0f && model[2][2] == 0.0f || model[3][3] == 0.0f){
        Logger::getInstance().warn("Model matrix is invalid, supplying identifty matrix");
        return glm::mat4(1.0f);
    }
    //if the matrix is valid, fully display it, line by line
    Logger::getInstance().warn("Model matrix: ");
    Logger::getInstance().warn(std::to_string(model[0][0]) + " " + std::to_string(model[0][1]) + " " + std::to_string(model[0][2]) + " " + std::to_string(model[0][3]));
    Logger::getInstance().warn(std::to_string(model[1][0]) + " " + std::to_string(model[1][1]) + " " + std::to_string(model[1][2]) + " " + std::to_string(model[1][3]));
    Logger::getInstance().warn(std::to_string(model[2][0]) + " " + std::to_string(model[2][1]) + " " + std::to_string(model[2][2]) + " " + std::to_string(model[2][3]));
    Logger::getInstance().warn(std::to_string(model[3][0]) + " " + std::to_string(model[3][1]) + " " + std::to_string(model[3][2]) + " " + std::to_string(model[3][3]));
    return model;
}

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