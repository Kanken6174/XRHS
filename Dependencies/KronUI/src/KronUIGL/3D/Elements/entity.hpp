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
    // stores the entity's XYZ rotation and translation + scale
    std::shared_ptr<Transform> transform = std::make_shared<QuaternionTransform>();
    
    // this is used to store the children of this entity as part of the scene graph
    std::vector<Entity> children;
    std::optional<Entity*> parent = std::nullopt;

    // an entity can have a 3d mesh
    std::optional<std::shared_ptr<Mesh>> mesh = std::nullopt;

    bool visible = true;

    Entity() {}
    Entity(float x, float y, float z) {transform->setEulerAngles(glm::vec3(x,y,z));}
    Entity(float x, float y, float z, float rx, float ry, float rz) {transform->setEulerAngles(glm::vec3(rx,ry,rz)); transform->setPosition(glm::vec3(x,y,z));}

    virtual glm::mat4 getTransformMatrix() const;
};