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

    unsigned int VAO, VBO, EBO,TBO;

    GLuint shaderID;

    bool hasNormals = false;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    std::function<void()> Draw;

    void setupMesh(GLuint shaderProgram);
};