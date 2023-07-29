#ifndef guard_georenderer
#define guard_georenderer
#include <GL/glew.h>
#include "./Shapes.hpp"
#include <GLFW/glfw3.h>

#include <vector>
#include <map>

class GeometryRenderer{
private:
    std::vector<DrawableElement*> elements;
    std::map<int,float*> arrays;
public:
    void addShapeToBuffer(DrawableElement* toRender);
    void renderAll();
};

#endif