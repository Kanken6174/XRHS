#include <memory>
#include "../../Shaders/Shader.hpp"
#include "../Elements/texture.hpp"

class VideoFrame {
    Texture texture;
    std::shared_ptr<Shader> shader;
    GLuint VAO, VBO;
    std::vector<GLfloat> vertices = {
        // Positions   // Texture Coords
        -1.0f,  1.0f,  0.0f, 0.0f,
        -1.0f, -1.0f,  0.0f, 1.0f,
        1.0f, -1.0f,  1.0f, 1.0f,

        -1.0f,  1.0f,  0.0f, 0.0f,
        1.0f, -1.0f,  1.0f, 1.0f,
        1.0f,  1.0f,  1.0f, 0.0f
    };
    bool back;
public:
    int width, height;  //(texture size)
    VideoFrame(const std::string& pngPath, std::shared_ptr<Shader> shader, GLFWwindow* window, bool back)
        : shader(shader), back(back) {
        Logger::getInstance().info("Loading texture from " + pngPath);
        glfwGetFramebufferSize(window, &width, &height);
        texture = Texture::loadFromPng(pngPath);
        setupQuad();
    }

    ~VideoFrame() {
        Logger::getInstance().info("Deleting texture with id " + std::to_string(texture.id));
        glDeleteTextures(1, &texture.id);
    }

    void setupQuad() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
        glBindBuffer(GL_ARRAY_BUFFER, 0);  
        glBindVertexArray(0);
    }

    void renderQuad() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }

    void updateFrame(const void *pixels) {
        glBindTexture(GL_TEXTURE_2D, texture.id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
        Logger::getInstance().info("Updated frame with new pixels");
    }

    void prepareFrame() {
        glBindTexture(GL_TEXTURE_2D, texture.id);
        shader->use();
        shader->setVec2("resolution", glm::vec2(width, height)); // Set the resolution uniform here
        Logger::getInstance().info("Preparing frame for rendering");
    }

    GLuint getTextureID() {
        Logger::getInstance().info("Getting texture ID: " + std::to_string(texture.id));
        return texture.id;
    }

    void render() {
        GLenum originalDepthFunc;
        glGetIntegerv(GL_DEPTH_FUNC, (GLint*)&originalDepthFunc); // store original depth function

        if (back) {
            glDepthFunc(GL_LESS);
        } else {
            glDepthFunc(GL_ALWAYS);
        }
        glDepthMask(GL_FALSE);
        prepareFrame();
        renderQuad();
        glDepthMask(GL_TRUE);

        glDepthFunc(originalDepthFunc); // reset to original depth function
    }
};