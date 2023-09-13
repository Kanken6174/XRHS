#ifndef guard_georenderer
#define guard_georenderer
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <map>
#include <memory>

class DrawableElement;

class GeometryRenderer{
private:
    std::map<int,float*> arrays;
public:
    void prepareShape(std::shared_ptr<DrawableElement> toRender);
    void renderAll();
};

#endif