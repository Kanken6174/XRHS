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