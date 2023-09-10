#pragma once
#ifndef guard_vert
#define guard_vert

#include <glm/glm.hpp>
#include <vector>

struct Vertex {
    glm::vec3 Position;
    glm::vec2 TexCoords;
    glm::vec3 Normal;
};

std::vector<Vertex> from3FloatVector(std::vector<float> floats);

#endif