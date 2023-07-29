#include "camera.hpp"

Camera::Camera(float width, float height, float nearPlane, float farPlane)
    : Entity(0.0f, 0.0f, 0.0f),
      projectionMatrix(glm::perspective(glm::radians(45.0f), width / height, nearPlane, farPlane)),
      viewMatrix(glm::lookAt(transform->getPosition(), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))) 
      {}

void Camera::updateViewMatrix() {
    viewMatrix = glm::lookAt(transform->getPosition(), transform->getPosition() + transform->getForward(), transform->getUp());
}