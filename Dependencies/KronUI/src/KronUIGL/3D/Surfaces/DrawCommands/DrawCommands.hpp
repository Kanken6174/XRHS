#include "../UIDrawSurface.hpp"
#include "../../Intersector/Intersector.hpp"

#pragma region forward_declarations
class TextRenderer;
class shapeElement;
class GeometryRenderer;
class DrawableElement;
#pragma endregion

class TextDrawCommand : public DrawCommand {
protected:
    std::string text;
    glm::vec2 position;
    glm::vec3 color;
    std::shared_ptr<TextRenderer> renderer;
    float scale;
public: 
    TextDrawCommand(std::shared_ptr<TextRenderer> renderer, std::string text, glm::vec2 position, glm::vec3 color, float scale) 
    : renderer(renderer),text(text), position(position), color(color), scale(scale) {}
    void Execute() override;
    void setText(std::string text) {this->text = text;}
};

class ShapeDrawCommand : public DrawCommand {
protected:
    std::shared_ptr<DrawableElement> element;
public:
    //note: the shape MUST be "prepared" before being passed to this command
    ShapeDrawCommand(std::shared_ptr<DrawableElement> element);
    void Execute() override;
};

class ButtonDrawCommand : public DrawCommand {
protected:
    std::shared_ptr<TextDrawCommand> text;
    std::shared_ptr<ShapeDrawCommand> shape;
    std::shared_ptr<DrawableElement> element;
    std::shared_ptr<TextRenderer> renderer;
    std::shared_ptr<GeometryRenderer> geomRenderer;
    glm::vec4 color = glm::vec4(1.0f,0.0f,0.0f,0.5f);
    glm::vec4 colorB = glm::vec4(1.0f,1.0f,1.0f,0.5f);
    bool secondary = false;
public:
    ButtonDrawCommand(std::shared_ptr<TextRenderer> renderer, std::shared_ptr<GeometryRenderer> geomRenderer, std::string text, glm::vec2 position, glm::vec2 scale = glm::vec2(1.0f,1.0f));
    void Execute() override;
    void setColorB(bool secondary) {this->secondary = secondary;}
    void setText(std::string text) {this->text->setText(text);}
};

class ButtonColorToggleCommand : public BoolCommand {
protected:
    std::shared_ptr<ButtonDrawCommand> button;
public:
    ButtonColorToggleCommand(std::shared_ptr<ButtonDrawCommand> button);
    void Execute() override {
        glm::vec2 vec = Intersector::getInstance()->getLastEvent().getFaceXY();
        bool value = vec.x > 0.0f && vec.y > 0.0f;
        button->setColorB(value);
        //display x and y values on the button
        button->setText(std::to_string(vec.x) + " " + std::to_string(vec.y));
    }
};