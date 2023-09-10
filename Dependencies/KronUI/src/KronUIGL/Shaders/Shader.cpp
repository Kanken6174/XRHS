#include "Shader.hpp"
#include "../Input/Input.hpp"

void Shader::cameraMatrixOp() const
{
    setMat4("view", InputSystem::getInstance().getCamera().viewMatrix);
    setMat4("projection", InputSystem::getInstance().getCamera().projectionMatrix);
    setMat4("model", glm::mat4(1.0f));
}