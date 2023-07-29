#include "DrawSurface.hpp"
#include <GL/glew.h>
#include "../../../../include/logger.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xinerama.h>

#include "../../Shaders/ShaderManager.hpp"

DrawSurface::DrawSurface(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::shared_ptr<Transform> transform)
    : vertices(std::move(vertices)), indices(std::move(indices)), transform(std::move(transform))
{
    glGenBuffers(1, &PBO);
}

DrawSurface::DrawSurface(const glm::vec2& size, std::vector<unsigned int> indices, std::shared_ptr<Transform> transform)
    : indices(std::move(indices)), transform(std::move(transform))
{
    Rectangle rect = Rectangle(size);
    std::vector<float> vertices = rect.generateVertices();
    //output all the vertices
    for(int i = 0; i < vertices.size(); i++){
        std::cout << ' ' << vertices[i] << std::endl;
    }
    for (int i = 0; i < vertices.size(); i += 3) {
        Vertex v;
        v.Position = glm::vec3(vertices[i], vertices[i + 1], vertices[i + 2]);
        //Texture coordinates. You'll need to adjust these if your vertices aren't arranged in a simple rectangle.
        if (i == 0) // bottom-left corner
                v.TexCoords = glm::vec2(0.0f, 1.0f);
            else if (i == 3) // bottom-right corner
                v.TexCoords = glm::vec2(1.0f, 1.0f);
            else if (i == 6) // top-right corner
                v.TexCoords = glm::vec2(1.0f, 0.0f);
            else // top-left corner
                v.TexCoords = glm::vec2(0.0f, 0.0f);
        v.Normal = glm::vec3(0.0f, 0.0f, 0.0f);
        this->vertices.push_back(v);
        //log all data
        Logger::getInstance().warn("Vertex: " + std::to_string(v.Position.x) + " " + std::to_string(v.Position.y) + " " + std::to_string(v.Position.z));
        Logger::getInstance().warn("Texture: " + std::to_string(v.TexCoords.x) + " " + std::to_string(v.TexCoords.y));
    }
    glGenBuffers(1, &PBO);
}

void DrawSurface::setupSurface(GLuint textureId, GLuint PBO) {
    this->textureId = textureId;
    this->PBO = PBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void DrawSurface::setupSurface() {
    // Generate and bind a new texture object
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Generate random pixel data
    int width = 1920;
    int height = 1080;
    std::vector<unsigned char> pixelData(3 * width * height);
    /*for (auto& pixel : pixelData) {
        pixel = std::rand() % 256; // Random value between 0 and 255
    }*/

    // Allocate and populate texture memory
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData.data());

    // Proceed as in the original method
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void DrawSurface::updateSurface(const void* pixelData, GLsizeiptr size) {
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, PBO);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, size, pixelData, GL_STREAM_DRAW);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 9000, 9000, GL_RGB, GL_UNSIGNED_BYTE, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

void DrawSurface::updateSurfaceRandom() {
    // Generate new random pixel data
    int width = 9000;
    int height = 9000;
    std::vector<unsigned char> pixelData(3 * width * height);
    for (int i = 0; i < pixelData.size(); i += 3) {
        pixelData[i + 0] = std::rand() % 256; // Random value for red
        pixelData[i + 1] = std::rand() % 256; // Random value for green
        pixelData[i + 2] = std::rand() % 256; // Random value for blue
    }

    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Update the texture with the new pixel data
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixelData.data());
}

void DrawSurface::updateSurfaceFromWindow() {
    Display* display = XOpenDisplay(NULL);
    if (!display) {
        std::cerr << "Unable to open X display." << std::endl;
        return;
    }

    if (!XineramaIsActive(display)) {
        std::cerr << "Xinerama is not active." << std::endl;
        XCloseDisplay(display);
        return;
    }

    int numberOfScreens;
    XineramaScreenInfo* screens = XineramaQueryScreens(display, &numberOfScreens);
    if (numberOfScreens < 2) {
        std::cerr << "Not enough screens." << std::endl;
        XFree(screens);
        XCloseDisplay(display);
        return;
    }

    // Get the info for the second screen
    XineramaScreenInfo screenInfo = screens[0];

    // Get the root window for the entire display, then capture only the area of the second screen
    Window window = XRootWindow(display, 0);  

    int x = screenInfo.x_org;
    int y = screenInfo.y_org;
    int width = screenInfo.width;
    int height = screenInfo.height;

    XImage* xImage = XGetImage(display, window, x, y, width, height, AllPlanes, ZPixmap);

    std::vector<unsigned char> pixelData(3 * width * height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned long pixel = XGetPixel(xImage, x, y);
            unsigned char blue = pixel & xImage->blue_mask;
            unsigned char green = (pixel & xImage->green_mask) >> 8;
            unsigned char red = (pixel & xImage->red_mask) >> 16;
            pixelData[3 * (y * width + x) + 0] = red;
            pixelData[3 * (y * width + x) + 1] = green;
            pixelData[3 * (y * width + x) + 2] = blue;
        }
    }

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixelData.data());
    Logger::getInstance().info("image updated with size: " + std::to_string(width) + "x" + std::to_string(height));

    XDestroyImage(xImage);
    XCloseDisplay(display);
}

void DrawSurface::drawSurface(glm::mat4 &view, glm::mat4 &projection) {
    ShaderManager::getInstance()->setShader(shader);
    // Set the shader uniforms for the model, view, and projection matrices.
    // `transform->getMatrix()` is a hypothetical function that returns the model matrix for this surface.
    glm::mat4 model = transform->getTransformMatrix();
    shader->setMat4("model", model); 
    // Bind the texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Tell the shader that texture unit 0 (which we activated and bound the texture to) should be used for the "texture1" sampler
    shader->setInt("texture1", 0);

    // Draw the surface
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
