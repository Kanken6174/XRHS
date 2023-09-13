#include "DrawCommands.hpp"
#include "../../../Text/TextRenderer.hpp"
#include "../../../Geometry/Shapes.hpp"
#include "../../../Geometry/GeometryRenderer.hpp"

void TextDrawCommand::Execute(){
    renderer->RenderText(text, position.x, position.y, scale, color);
}

ShapeDrawCommand::ShapeDrawCommand(std::shared_ptr<DrawableElement> element): element(element)
{
    if(!element->drawerFunction)
        Logger::getInstance().fatal("element->drawerFunction was null, impossible to add to ShapeDrawCommand");
}

void ShapeDrawCommand::Execute()
{
    element->drawSelf();
}