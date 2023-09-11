#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <optional>
#include "transform.hpp"
#include "texture.hpp"
#include "mesh.hpp"
#include <memory>

/*
* this class is used to represent an entity in 3D space
*/
class Entity {
public:
    std::string name = "UnNamed Entity";
    // stores the entity's XYZ rotation and translation + scale from its parent, if it has one
    std::shared_ptr<Transform> localTransform = std::make_shared<QuaternionTransform>();
    // stores the entity's XYZ rotation and translation + scale from the world origin (only calculated when needed)
    std::shared_ptr<Transform> transform = std::make_shared<QuaternionTransform>();
    
    // this is used to store the children of this entity as part of the scene graph
    std::vector<std::shared_ptr<Entity>> children;
    std::optional<std::shared_ptr<Entity>> parent = std::nullopt;

    // an entity can have a 3d mesh
    std::shared_ptr<Mesh> mesh;
    bool visible = true;

    Entity() {}
    Entity(std::shared_ptr<Entity> myParent) : parent(myParent) {}
    Entity(float x, float y, float z) {transform->setEulerAngles(glm::vec3(x,y,z));}
    Entity(float x, float y, float z, float rx, float ry, float rz) {transform->setEulerAngles(glm::vec3(rx,ry,rz)); transform->setPosition(glm::vec3(x,y,z));}

    virtual glm::mat4 getTransformMatrix() const;
};