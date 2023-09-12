#include "../UIDrawSurface.hpp"

#pragma region forward_declarations
class TextRenderer;
#pragma endregion

class TextDrawCommand : public DrawCommand {
protected:
    std::string text;
    glm::vec2 position;
    glm::vec3 color;
    std::shared_ptr<TextRenderer> renderer;
    float scale;
public: 
    TextDrawCommand(std::shared_ptr<TextRenderer> renderer,std::shared_ptr<DrawSurface> surface, std::string text, glm::vec2 position, glm::vec3 color, float scale) 
    : DrawCommand(surface), renderer(renderer),text(text), position(position), color(color), scale(scale) {}
    void Execute() override;
};