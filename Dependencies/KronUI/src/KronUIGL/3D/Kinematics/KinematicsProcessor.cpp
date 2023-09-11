#include "KinematicsProcessor.hpp"
#include "../Elements/world.hpp"

void processLocalTransforms(std::shared_ptr<Entity> parent) {
    for(auto& child : parent->children) {  //iterate through the children
        child->transform = parent->localTransform->offsetOP(child->localTransform);    //apply parent transform to child
        processLocalTransforms(child);  //recursive
    }
}

void processWorldTransforms() {
    auto world = World::getInstance();
    for (auto& entity : world->children) {  //iterate through the parent entities
        entity->transform = entity->localTransform;  //apply parent transform to child
        processLocalTransforms(entity); //recursive
    }
}