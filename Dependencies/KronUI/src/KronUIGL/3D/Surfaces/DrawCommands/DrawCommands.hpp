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