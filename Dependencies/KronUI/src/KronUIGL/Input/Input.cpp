#include "./Input.hpp"

InputSystem InputSystem::instance;

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    static std::optional<std::pair<double, double>> lastPos;

    if (!lastPos) {
        lastPos.emplace(xpos, ypos);
        return;
    }

    double xoffset = xpos - lastPos->first; 
    double yoffset = ypos - lastPos->second;

    lastPos->first = xpos;
    lastPos->second = ypos;

    // Update camera rotation
    InputSystem::getInstance().getCamera().rotate(
        glm::vec3(yoffset, xoffset, 0.0) * 0.15f);
}

void processInput(GLFWwindow* window, float deltaTime) {
    for (const auto& [key, action] : InputSystem::getInstance().keyActions) {
        if (glfwGetKey(window, key) == GLFW_PRESS) {
            action();
            InputSystem::getInstance().getCamera().updateViewMatrix();
        }
    }
}