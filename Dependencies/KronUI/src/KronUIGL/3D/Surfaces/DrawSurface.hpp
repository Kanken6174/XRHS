#pragma once
#include <GL/glew.h>
#include <memory>
#include <vector>

#include "./../Elements/transform.hpp"
#include "../../Shaders/Shader.hpp"
#include "./../Elements/entity.hpp"
#include <memory>

class DrawSurface : public Entity{
protected:
    GLuint textureId;
    GLuint PBO;

    GLuint VAO, VBO, EBO;
    glm::vec2 _size;
public:
    std::shared_ptr<Shader> shader;

    DrawSurface(const glm::vec2& size, std::vector<unsigned int> indices, std::shared_ptr<Transform> transform);
    DrawSurface(const glm::vec2& size, std::shared_ptr<Transform> transform);
    virtual void setupSurface();

    static std::vector<unsigned int> defaultIndicies() {
        std::vector<unsigned int> indices = {0, 1, 2, 2, 3, 0};
        return indices;
    }
};