#pragma once
#include "DrawSurface.hpp"
class Vertex;

class X11DrawSurface : public DrawSurface{
public:

    X11DrawSurface(const glm::vec2& size, std::shared_ptr<Transform> transform) : DrawSurface(size, transform) {}

    void updateSurface(const void* pixelData, GLsizeiptr size);
    void updateSurfaceRandom();
    void updateSurfaceFromWindow();
    void drawSurface(glm::mat4 &view, glm::mat4 &projection);
};