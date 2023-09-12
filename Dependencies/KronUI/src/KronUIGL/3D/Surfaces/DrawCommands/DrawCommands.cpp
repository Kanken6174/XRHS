#include "DrawCommands.hpp"
#include "../../../Text/TextRenderer.hpp"

void TextDrawCommand::Execute(){
    renderer->RenderText(text, position.x, position.y, scale, color);
}