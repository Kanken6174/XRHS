#pragma once

#include <vector>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../Shaders/Shader.hpp"
#include "../Loaders/OBJLoader.hpp"
#include "../Elements/entity.hpp"

//renders the meshes within an entity
class MeshRenderer {
private:
    std::vector<std::shared_ptr<Entity>> managedEntities;
    std::vector<std::shared_ptr<Mesh>> meshes;  //deprecated
    //debugging only
    unsigned int quadVAO = 0;
    unsigned int quadVBO;
    void prepareQuad();
    void drawQuad();
public:
    std::shared_ptr<Shader> shader;
    MeshRenderer(std::shared_ptr<Shader> _shader) : shader(_shader) {}
    
    void drawMesh(std::shared_ptr<Mesh> mesh);

    void renderAllWorld();  //renders all entities in the world
    void renderSingle(const std::shared_ptr<Entity>& entity);
protected:
    void renderChildren(const std::shared_ptr<Entity>& entity);
};