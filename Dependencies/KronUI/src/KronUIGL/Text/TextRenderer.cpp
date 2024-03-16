#include "./TextRenderer.hpp"
#include "../Shaders/Shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

TextRenderer::TextRenderer(std::shared_ptr<Shader> shader, KronUIWindow* window, TrueTypeManager* ttfManager) : _shader(shader), _window(window), _ttfManager(ttfManager){
    //setup the shader
    _screenSize = glm::vec2(window->_width, window->_height);
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window->_width), 0.0f, static_cast<float>(window->_height));
    ShaderManager::getInstance()->setShader(_shader);
    glUniformMatrix4fv(glGetUniformLocation(_shader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
}



void TextRenderer::RenderText(std::string text, float x, float y, float scale, glm::vec3 color){
    // activate corresponding render state
    ShaderManager::getInstance()->setShader(_shader);
    glUniform3f(glGetUniformLocation(_shader->ID, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(_window->VAO);

    // iterate through all characters
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++) 
    {
        Character ch = _ttfManager->Characters[*c];

        float xpos = x + ch.Bearing.x * scale;
        float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;
        // update VBO for each character
        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },            
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }           
        };
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);

        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, _window->VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}