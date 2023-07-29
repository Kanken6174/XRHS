#include "transform.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/quaternion.hpp>

glm::mat4 Transform::getTransformMatrix() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, getPosition());
    model = glm::rotate(model, glm::radians(getEulerAngles().x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(getEulerAngles().y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(getEulerAngles().z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, getScale());

    return model;
}

// EulerTransform implementation
EulerTransform::EulerTransform() : position(0.0f), scale(1.0f), eulerAngles(0.0f) {}

EulerTransform::EulerTransform(glm::vec3 position, glm::vec3 scale, glm::vec3 eulerAngles)
    : position(position), scale(scale), eulerAngles(eulerAngles) {}

glm::vec3 EulerTransform::getPosition() const {
    return position;
}

void EulerTransform::setPosition(const glm::vec3& position) {
    this->position = position;
}

glm::vec3 EulerTransform::getScale() const {
    return scale;
}

void EulerTransform::setScale(const glm::vec3& scale) {
    this->scale = scale;
}

glm::vec3 EulerTransform::getEulerAngles() const {
    return eulerAngles;
}

void EulerTransform::setEulerAngles(const glm::vec3& eulerAngles) {
    this->eulerAngles = eulerAngles;
}

glm::quat EulerTransform::getQuaternion() const {
    return glm::quat(eulerAngles);
}

void EulerTransform::setQuaternion(const glm::quat& quaternion) {
    eulerAngles = glm::eulerAngles(quaternion);
}

void EulerTransform::translate(const glm::vec3& translation) {
    position += translation;
}

void EulerTransform::rotate(const glm::vec3& rotation) {
    eulerAngles += rotation;
}

glm::vec3 EulerTransform::getForward() const {
    return glm::normalize(getQuaternion() * glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::vec3 EulerTransform::getUp() const {
    return glm::normalize(glm::cross(getRight(), getForward()));
}

glm::vec3 EulerTransform::getRight() const {
    return glm::normalize(glm::cross(getForward(), glm::vec3(0.0f, 1.0f, 0.0f)));
}


// QuaternionTransform implementation
QuaternionTransform::QuaternionTransform() : position(0.0f), scale(1.0f), rotation(glm::vec3(0.0f)) {}

QuaternionTransform::QuaternionTransform(glm::vec3 position, glm::vec3 scale, glm::quat rotation)
    : position(position), scale(scale), rotation(rotation) {}

glm::vec3 QuaternionTransform::getPosition() const {
    return position;
}

void QuaternionTransform::setPosition(const glm::vec3& position) {
    this->position = position;
}

glm::vec3 QuaternionTransform::getScale() const {
    return scale;
}

void QuaternionTransform::setScale(const glm::vec3& scale) {
    this->scale = scale;
}

glm::vec3 QuaternionTransform::getEulerAngles() const {
    return glm::eulerAngles(rotation);
}

void QuaternionTransform::setEulerAngles(const glm::vec3& eulerAngles) {
    rotation = glm::quat(eulerAngles);
}

glm::quat QuaternionTransform::getQuaternion() const {
    return rotation;
}

void QuaternionTransform::setQuaternion(const glm::quat& quaternion) {
    rotation = quaternion;
}

void QuaternionTransform::translate(const glm::vec3& translation) {
    position += translation;
}

void QuaternionTransform::rotate(const glm::vec3& rotation) {
    glm::quat qPitch = glm::angleAxis(glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::quat qYaw = glm::angleAxis(glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::quat qRoll = glm::angleAxis(glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::quat orientation = qPitch * qYaw * qRoll;
    this->rotation = glm::normalize(orientation * rotation);
}

glm::vec3 QuaternionTransform::getForward() const {
    return glm::normalize(rotation * glm::vec3(0.0f, 0.0f, -1.0f));
}

glm::vec3 QuaternionTransform::getUp() const {
    return glm::normalize(glm::cross(getRight(), getForward()));
}

glm::vec3 QuaternionTransform::getRight() const {
    return glm::normalize(glm::cross(getForward(), glm::vec3(0.0f, 1.0f, 0.0f)));
}

glm::mat4 QuaternionTransform::getTransformMatrix() const {
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), getPosition());
    glm::mat4 rotation = glm::toMat4(getQuaternion());
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), getScale());

    // Perform scaling, then rotation, then translation
    return translation * rotation * scale;
}