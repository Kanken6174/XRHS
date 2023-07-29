#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


#include "../Elements/entity.hpp"

class Camera : public Entity {
public:
    glm::mat4 projectionMatrix = glm::mat4(0.0f);
    glm::mat4 viewMatrix = glm::mat4(0.0f);

    Camera(float width, float height, float nearPlane = 0.1f, float farPlane = 100.0f);

    void updateViewMatrix();

    void translate(glm::vec3 translation) {
        transform->setPosition(transform->getPosition() += translation);
        updateViewMatrix();
    }

    void rotate(glm::vec3 rotation) {
        glm::quat qPitch = glm::angleAxis(glm::radians(rotation.x), transform->getRight());
        glm::quat qYaw = glm::angleAxis(glm::radians(rotation.y), transform->getUp());
        glm::quat qRoll = glm::angleAxis(glm::radians(rotation.z), transform->getForward());
        glm::quat orientation = qPitch * qYaw * qRoll;
        transform->setQuaternion(glm::normalize(orientation * transform->getQuaternion()));
        updateViewMatrix();
    }

    
    glm::vec3 getRotation() const {
        return transform->getEulerAngles();
    }

    Camera(){}
};