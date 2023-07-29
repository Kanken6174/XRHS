#pragma once

#include <GL/glew.h>
#include <memory>
#include <vector>
#include "./../Elements/vertex.hpp"
#include "./../Elements/transform.hpp"
#include "../../Geometry/Shapes.hpp"
#include "../../Shaders/Shader.hpp"
#include <memory>

class DrawSurface {
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::shared_ptr<Transform> transform; // transform relative to the parent entity

    GLuint textureId;
    GLuint PBO;

    GLuint VAO, VBO, EBO;

    std::shared_ptr<Shader> shader;

    static std::vector<unsigned int> defaultIndicies() {
        std::vector<unsigned int> indices = {0, 1, 2, 2, 3, 0};
        return indices;
    }

    DrawSurface(const glm::vec2& size, std::vector<unsigned int> indices, std::shared_ptr<Transform> transform);
    DrawSurface(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::shared_ptr<Transform> transform);
    void setupSurface(GLuint textureId, GLuint PBO);
    void setupSurface();
    void updateSurface(const void* pixelData, GLsizeiptr size);
    void updateSurfaceRandom();
    void updateSurfaceFromWindow();
    void drawSurface(glm::mat4 &view, glm::mat4 &projection);
};