#ifndef guard_drawing
#define guard_drawing
#include <GL/glew.h>
#include "../Shaders/Shader.hpp"
#define VERTICES_SIZE 3
#include <vector>
#include <iostream>
#include <memory>

enum class RenderMode {Triangles, Lines, Quads,Triangles_fanout};

class Transform;

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
    //usually not the DrawableElement's transform, but the transform of the object that contains it
    std::shared_ptr<Transform> storedTransform;
    RenderMode mode = RenderMode::Triangles_fanout;
    GLuint bufferID;
    std::shared_ptr<Shader> shader;
    glm::vec4 geomColor;
    void (*drawerFunction)(DrawableElement*);
    void drawSelf();
};

#endif