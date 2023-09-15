#include "../UIDrawSurface.hpp"

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
    ButtonDrawCommand(std::shared_ptr<TextRenderer> renderer, std::shared_ptr<GeometryRenderer> geomRenderer, std::string text, glm::vec2 position);
    void Execute() override;
    void setColorB(bool secondary) {this->secondary = secondary;}
};

class ButtonColorToggleCommand : public BoolCommand {
protected:
    std::shared_ptr<ButtonDrawCommand> button;
public:
    ButtonColorToggleCommand(std::shared_ptr<ButtonDrawCommand> button);
    void Execute() override {button->setColorB(value);}
};