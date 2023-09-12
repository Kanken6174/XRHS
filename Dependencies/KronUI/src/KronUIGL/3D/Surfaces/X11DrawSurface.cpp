#include "X11DrawSurface.hpp"
#include <GL/glew.h>
#include "../../../../include/logger.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xinerama.h>

#include "../../Shaders/ShaderManager.hpp"
#include "../../Geometry/Shapes.hpp"

void X11DrawSurface::updateSurface(const void* pixelData, GLsizeiptr size) {
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, PBO);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, size, pixelData, GL_STREAM_DRAW);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 2000, 2000, GL_RGB, GL_UNSIGNED_BYTE, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
}

void X11DrawSurface::updateSurfaceRandom() {
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

void X11DrawSurface::updateSurfaceFromWindow() {
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

void X11DrawSurface::drawSurface(glm::mat4 &view, glm::mat4 &projection) {
    ShaderManager::getInstance()->setShader(shader);
    // Set the shader uniforms for the model, view, and projection matrices.
    glm::mat4 model = transform->getTransformMatrix();
    shader->setMat4("model", model); 
    // Bind the texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Tell the shader that texture unit 0 (which we activated and bound the texture to) should be used for the "texture1" sampler
    shader->setInt("texture1", 0);

    // Draw the surface
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}