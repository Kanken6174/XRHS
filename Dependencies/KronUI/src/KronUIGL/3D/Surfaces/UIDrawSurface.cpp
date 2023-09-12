#include "UIDrawSurface.hpp"

void UIDrawSurface::setupSurface(){
    // Generate and bind a framebuffer object (FBO)
    GLuint framebuffer;
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);

    // Create a texture to render to
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture parameters (adjust these according to your needs)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Attach the texture as the color attachment to the framebuffer
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

    // Check if the framebuffer is complete
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        // Handle framebuffer setup error
    }

    // Unbind the framebuffer when you're done
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // You can save the framebuffer and texture IDs as member variables for future reference
    framebufferId = framebuffer;
    textureId = texture;
}

//bind the framebuffer object
void UIDrawSurface::FBOBegin()
{
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);
}

//unbind the framebuffer object
void UIDrawSurface::FBOEnd()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void UIDrawSurface::runCommands() {
    FBOBegin();
    shader->use();
    for (auto command : drawCommands) {
        command->Execute();
    }
    //now update the texture
    glBindTexture(GL_TEXTURE_2D, textureId);
    // Use glCopyTexImage2D to copy the framebuffer's contents to the texture
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 0, 0, 2000, 2000, 0);
    FBOEnd();
}