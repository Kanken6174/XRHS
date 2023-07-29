#pragma once

#include "vertex.hpp"
#include "texture.hpp"
#include "transform.hpp"

#include <GL/glew.h>
#include <functional>
#include <memory>

class Mesh {
public:
    // Mesh data
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    std::shared_ptr<Transform> transform;    //transform relative to the parent entity

    unsigned int VAO, VBO, EBO,TBO;

    GLuint shaderID;

    bool hasNormals = false;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, std::shared_ptr<Transform> transform);
    std::function<void()> Draw;
    glm::mat4 getTransformMatrix() const;

    void setupMesh(GLuint shaderProgram);
};