#pragma once
#ifndef guard_vert
#define guard_vert

#include <glm/glm.hpp>
#include <vector>

struct Vertex {
    glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec2 TexCoords = glm::vec2(0.0f, 0.0f);
    glm::vec3 Normal = glm::vec3(0.0f, 0.0f, 0.0f);
};

std::vector<Vertex> from3FloatVector(std::vector<float> floats);

#endif