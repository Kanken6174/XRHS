#include <iostream>
#include <map>
#include <string>
#include "./../Shaders/Shader.hpp"
#include "./../Window/KronUIWindow.hpp"
#include "./../../Freetype/TrueTypeManager.hpp"

//a utility that can generate flat text on a X and Y coordinate
class TextRenderer{
private:
    std::shared_ptr<Shader> _shader;
    KronUIWindow* _window;
    TrueTypeManager* _ttfManager;
public:
    TextRenderer(std::shared_ptr<Shader> shader, KronUIWindow* window, TrueTypeManager* ttfManager);
    void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
};