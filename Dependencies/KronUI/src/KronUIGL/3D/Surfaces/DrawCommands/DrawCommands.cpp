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

ButtonDrawCommand::ButtonDrawCommand(std::shared_ptr<TextRenderer> renderer, std::shared_ptr<GeometryRenderer> geomRenderer, std::string text, glm::vec2 position, glm::vec2 scale) 
: renderer(renderer),  geomRenderer(geomRenderer)
{
    this->text = std::make_shared<TextDrawCommand>(renderer,text,glm::vec2((position.x*renderer->_screenSize.x)/2+20.0f* scale.x,(position.y*renderer->_screenSize.y)/2+200.0f* scale.x),glm::vec3(1.0f,0.0f,0.0f),9.0f * scale.x);
    this->element = std::make_shared<EmptyRectangle>(glm::vec3(position.x-1.0f,position.y-0.9f,0.0f),2.0f*scale.x,1.0f*scale.y,0.05f);
    this->element->geomColor = color;
    this->element->mode = RenderMode::Triangles;
    geomRenderer->prepareShape(element);
    this->shape = std::make_shared<ShapeDrawCommand>(element);
}

void ButtonDrawCommand::Execute()
{
    shape->Execute();
    this->element->geomColor = secondary ? colorB : color;
    text->Execute();    //draw text over shape
}

ButtonColorToggleCommand::ButtonColorToggleCommand(std::shared_ptr<ButtonDrawCommand> button)
{
    this->button = button;
    if(!button)
        Logger::getInstance().fatal("button was null, impossible to add to ButtonColorToggleCommand");
}