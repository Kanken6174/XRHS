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

ButtonDrawCommand::ButtonDrawCommand(std::shared_ptr<TextRenderer> renderer, std::shared_ptr<GeometryRenderer> geomRenderer, std::string text, glm::vec2 position) 
: renderer(renderer),  geomRenderer(geomRenderer)
{
    this->text = std::make_shared<TextDrawCommand>(renderer,text,glm::vec2((position.x*1920)/2+20.0f,(position.y*1080)/2+200.0f),glm::vec3(1.0f,0.0f,0.0f),10.0f);
    this->element = std::make_shared<EmptyRectangle>(glm::vec3(position.x-1.0f,position.y-0.9f,0.0f),2.0f,1.0f,0.05f);
    this->element->geomColor = glm::vec4(1.0f,0.0f,0.0f,0.5f);  //red?
    this->element->mode = RenderMode::Triangles;
    geomRenderer->prepareShape(element);
    this->shape = std::make_shared<ShapeDrawCommand>(element);
}

void ButtonDrawCommand::Execute()
{
    shape->Execute();
    text->Execute();    //draw text over shape
}