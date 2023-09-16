#include "Drawing.hpp"
#include "../../../include/logger.hpp"

void DrawableElement::drawSelf(){
    shader->use();
    cameraMatrixOp(shader);
    if(drawerFunction != nullptr)
        drawerFunction(this);
    else
        Logger::getInstance().fatal("drawer function was null on drawable: " + std::to_string(bufferID));
}

std::shared_ptr<Shader> DebugDrawer::shader;

void DebugDrawer::drawPointVec3(glm::vec3 point, glm::vec4 color){
    shader->use();
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex3f(point.x, point.y, point.z);
    glEnd();
}