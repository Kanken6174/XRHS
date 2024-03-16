#include "entity.hpp"
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 Entity::getTransformMatrix() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, transform->getPosition());
    model = glm::rotate(model, glm::radians(transform->getEulerAngles().x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->getEulerAngles().y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(transform->getEulerAngles().z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, transform->getScale());

    return model;
}