#ifndef guard_drawing
#define guard_drawing
#include <GL/glew.h>
#include "../Shaders/Shader.hpp"
#define VERTICES_SIZE 3
#include <vector>
#include <iostream>
#include <memory>

enum class RenderMode {Triangles, Lines, Quads};

//Defines a primitive shape made out of computed verticies
class shapeElement{
protected:
    std::vector<float> vertices = std::vector<float>();
public:
    /// @brief Generates the vertices for a given shape, which can be read by opengl to draw things
    /// @return 
    unsigned int verticesAmount = 3;
    virtual std::vector<float> generateVertices()=0;
};

class DrawableElement : public shapeElement{
public:
    RenderMode mode = RenderMode::Triangles;
    GLuint bufferID;
    std::shared_ptr<Shader> shader;
    void (*drawerFunction)(DrawableElement*);
    void drawSelf(){
        shader->setInt("useDefault", 1);
        shader->setInt("useColor", 0);
        shader->setInt("useTexture", 0);
        shader->setInt("useBump", 0);
        shader->cameraMatrixOp();
        if(drawerFunction != nullptr)
            drawerFunction(this);
        else
            std::cout << "drawer function was null on drawable: " << this->bufferID << std::endl;
    }
};

#endif