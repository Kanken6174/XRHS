#ifndef guard_drawing
#define guard_drawing
#include <GL/glew.h>
#include "../Shaders/Shader.hpp"
#define VERTICES_SIZE 3
#include <vector>
#include <iostream>
#include <memory>

enum class RenderMode {Triangles, Lines, Quads,Triangles_fanout};

//Defines a primitive shape made out of computed verticies
class shapeElement{
protected:
    std::vector<float> vertices = std::vector<float>();
public:
    /// @brief Generates the vertices for a given shape, which can be read by opengl to draw things
    /// @return 
    unsigned int verticesAmount = 3;
    virtual std::vector<float> generateVertices() = 0;
};

class DrawableElement : public shapeElement{
public:
    RenderMode mode = RenderMode::Triangles_fanout;
    GLuint bufferID;
    std::shared_ptr<Shader> shader;
    glm::vec4 geomColor;
    void (*drawerFunction)(DrawableElement*);
    void drawSelf();
};

#endif