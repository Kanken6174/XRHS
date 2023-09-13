#include "UIDrawSurface.hpp"

void UIDrawSurface::setupUISurface(){
    // Generate and bind a framebuffer object (FBO)
    glGenFramebuffers(1, &framebufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);
    Logger::getInstance().warn("Framebuffer ID: " + std::to_string(framebufferId));

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1920, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    glGenVertexArrays(1, &VAO); //buffer generation
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(unsigned int), &mesh->indices[0], GL_STATIC_DRAW);

    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    // Attach the texture as the color attachment to the framebuffer
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureId, 0);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE){
        Logger::getInstance().warn("Framebuffer is complete!");
    }
    // Unbind the framebuffer when you're done
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
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
    // Check if the framebuffer is complete
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        switch(glCheckFramebufferStatus(GL_FRAMEBUFFER)){
            case GL_FRAMEBUFFER_UNDEFINED:
                Logger::getInstance().fatal("Framebuffer is undefined!");
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                Logger::getInstance().fatal("Framebuffer has incomplete attachment!");
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                Logger::getInstance().fatal("Framebuffer has missing attachment!");
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
                Logger::getInstance().fatal("Framebuffer has incomplete draw buffer!");
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
                Logger::getInstance().fatal("Framebuffer has incomplete read buffer!");
                break;
            case GL_FRAMEBUFFER_UNSUPPORTED:
                Logger::getInstance().fatal("Framebuffer is unsupported!");
                break;
        }
        Logger::getInstance().fatal("Framebuffer is not complete!");
    }
    //now update the texture
    glBindTexture(GL_TEXTURE_2D, textureId);
    // Use glCopyTexImage2D to copy the framebuffer's contents to the texture
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 0, 0, 1920, 1080, 0);
    FBOEnd();
    ready = true;
}

void UIDrawSurface::render(){
    if(!ready) return;
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
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, mesh->indices.data());
    glBindVertexArray(0);
}