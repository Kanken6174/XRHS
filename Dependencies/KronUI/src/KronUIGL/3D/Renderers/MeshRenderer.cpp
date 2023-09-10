#include "MeshRenderer.hpp"
#include "../../Shaders/ShaderManager.hpp"
#include "../../../../include/logger.hpp"
#include "../Elements/world.hpp"

void MeshRenderer::prepareQuad()
{
    float quadVertices[] = {
        // positions        // texture coords
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,    
    };
    
    if (quadVAO == 0)
    {
        glGenVertexArrays(1, &quadVAO);
        glGenBuffers(1, &quadVBO);
        glBindVertexArray(quadVAO);

        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    }
}

void MeshRenderer::drawQuad()
{
    glDisable(GL_DEPTH_TEST);
    glBindVertexArray(quadVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
    glEnable(GL_DEPTH_TEST);
}

void MeshRenderer::renderSingle(const std::shared_ptr<Mesh>& mesh) {
        // set the model matrix for the current mesh.
        glm::mat4 model = mesh->transform->getTransformMatrix();
        shader->setMat4("model", model);

        // Check the mesh's textures to enable or disable shader features.
        int useColor = 0, useTexture = 0, useBump = 0;
        unsigned int diffuseNr = 1;
        unsigned int normalNr = 1;
        int defaultMode = 0;

        //std::cout << "rendering model with: " << mesh->textures.size() << " textures" << std::endl;

        if(mesh->textures.size() == 0){
            defaultMode = 1;
        }else
            for (unsigned int i = 0; i < mesh->textures.size(); i++) {
                glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding

                // retrieve texture number (the N in diffuse_textureN)
                std::string number;
                std::string name = mesh->textures[i].type;
                if (name == "texture_diffuse") {
                    number = std::to_string(diffuseNr++);
                    useTexture = 1;
                }else if (name == "texture_normal") {
                    number = std::to_string(normalNr++);
                    useBump = 0;
                }
                shader->setInt(("material." + name + number).c_str(), i);
                glBindTexture(GL_TEXTURE_2D, mesh->textures[i].id);
            }
        shader->setInt("useDefault", (useColor == 0 && useTexture == 0 && useBump == 0) || defaultMode == 1 ? 1 : 0);
        shader->setInt("useColor", useColor);
        shader->setInt("useTexture", useTexture);
        shader->setInt("useBump", useBump);

        drawMesh(mesh);

        // Always good practice to set everything back to defaults once configured.
        glActiveTexture(GL_TEXTURE0);
}

void MeshRenderer::renderAll() {
    ShaderManager::getInstance()->setShader(shader);

    glm::mat4 model = glm::mat4(1.0f);

    for (const std::shared_ptr<Mesh>& mesh : meshes) {
       renderSingle(mesh);
    }
}

void MeshRenderer::renderAllWorld() {
    ShaderManager::getInstance()->setShader(shader);
    cameraMatrixOp(shader);

    auto worldInstance = World::getInstance();  

    Logger::getInstance().info("Rendering world with " + std::to_string(worldInstance->totalEntitiesRecurse()) + " entities and " + std::to_string(worldInstance->lights.size()) + " lights.");

    if(worldInstance == nullptr) {
        Logger::getInstance().error("World instance is null!");
    }
    if(worldInstance->children.size() == 0) {
        Logger::getInstance().error("World instance has no entities!");
    }

    if(worldInstance->lights.size() == 0) {
        Logger::getInstance().error("World instance has no lights!");
    }

    // Set light properties
    for(size_t i = 0; i < worldInstance->lights.size(); ++i) {
        std::string lightStr = "lights[" + std::to_string(i) + "]";
        shader->setVec3(lightStr + ".position", worldInstance->lights[i]->GetTransform()->getPosition());
        shader->setVec3(lightStr + ".color", worldInstance->lights[i]->GetColor());
    }
    shader->setInt("numLights", worldInstance->lights.size());
    int i = 0;
    // Render entities
    for(auto& entity : worldInstance->children) {
        renderChildren(entity);
    }
}

void MeshRenderer::renderChildren(const std::shared_ptr<Entity>& entity){
    if(entity->mesh && entity->transform && entity->mesh->get()->VAO != 0) {
        renderSingle(entity->mesh.value());
    }else{
        Logger::getInstance().error("Entity has no mesh or transform!");
    }
    for(auto& child : entity->children){
        renderChildren(child);
    }
}

void MeshRenderer::drawMesh(std::shared_ptr<Mesh> mesh) {
    glBindVertexArray(mesh->VAO);
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glDisable(GL_CULL_FACE);
}