#include "KinematicJoints.hpp"
//This kinematic joint just takes the parent' current transform and multiplies it by the child's local transform to obtain the child's current transform
void BasicKinematicJoint::update(shared_ptr<Entity> parent, shared_ptr<Entity> current)
{
    current->transform = parent->localTransform->offsetOP(current->localTransform);
}

// this joint will use the child's local transform to find out how far it is from the parent and will modify the rotation and position of the child
// this way if the parent is rotated, the child's psoition will change as if it was part of the parent
void DerivedKinematicJoint::update(shared_ptr<Entity> parent, shared_ptr<Entity> current)
{
    shared_ptr<Transform> cu = current->localTransform; // Offset from the parent
    shared_ptr<Transform> pt = parent->transform; // Parent's current position in the world

    // Calculate the child's position in the world by transforming its local position
    glm::vec3 childPos = pt->getQuaternion() * cu->getPosition() + pt->getPosition();

    // Calculate the child's rotation in the world by combining parent's and child's rotations
    glm::quat childRot = pt->getQuaternion() * cu->getQuaternion();

    // Set the child's final world transform
    current->transform->setPosition(childPos);
    current->transform->setQuaternion(childRot);
}