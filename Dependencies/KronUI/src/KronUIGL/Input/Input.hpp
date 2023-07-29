#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <optional>
#include <map>
#include <functional>

#include "../3D/Vision/camera.hpp"

class InputSystem{
    private:
        Camera camera = Camera(800, 600, 0.1f, 100.0f); 
        static InputSystem instance;
    public:
        const std::map<int, std::function<void()>> keyActions = {
            {GLFW_KEY_W, [this](){
                glm::vec3 moveDirection = this->camera.transform->getForward();
                moveDirection.y = 0; // prevent vertical movement
                this->camera.transform->setPosition(this->camera.transform->getPosition() + glm::normalize(moveDirection) * 0.15f);
            }},
            {GLFW_KEY_S, [this](){
                glm::vec3 moveDirection = this->camera.transform->getForward();
                moveDirection.y = 0; // prevent vertical movement
                this->camera.transform->setPosition(this->camera.transform->getPosition() - glm::normalize(moveDirection) * 0.15f);
            }},
            {GLFW_KEY_A, [this](){
                glm::vec3 moveDirection = glm::normalize(glm::cross(this->camera.transform->getForward(), glm::vec3(0.0f, 1.0f, 0.0f)));
                moveDirection.y = 0; // prevent vertical movement
                this->camera.transform->setPosition(this->camera.transform->getPosition() - moveDirection * 0.1f);
            }},
            {GLFW_KEY_D, [this](){
                glm::vec3 moveDirection = glm::normalize(glm::cross(this->camera.transform->getForward(), glm::vec3(0.0f, 1.0f, 0.0f)));
                moveDirection.y = 0; // prevent vertical movement
                this->camera.transform->setPosition(this->camera.transform->getPosition() + moveDirection * 0.1f);
            }},
            /*{GLFW_KEY_UP, [this](){ this->camera.transform->rotate(glm::vec3(-0.5f, 0.0f, 0.0f)); }},
            {GLFW_KEY_DOWN, [this](){ this->camera.transform->rotate(glm::vec3(0.5f, 0.0f, 0.0f)); }},
            {GLFW_KEY_LEFT, [this](){ this->camera.transform->rotate(glm::vec3(0.0f, -0.5f, 0.0f)); }},
            {GLFW_KEY_RIGHT, [this](){ this->camera.transform->rotate(glm::vec3(0.0f, 0.5f, 0.0f)); }},*/
            {GLFW_KEY_SPACE, [this](){ this->camera.transform->setPosition(this->camera.transform->getPosition() + this->camera.transform->getUp() * 0.1f); }},
            {GLFW_KEY_LEFT_CONTROL, [this](){ this->camera.transform->setPosition(this->camera.transform->getPosition() - this->camera.transform->getUp() * 0.1f); }},
            {GLFW_KEY_E, [this](){ this->camera.transform->rotate(glm::vec3(0.0f, 0.0f, -0.5f)); }},
            {GLFW_KEY_Q, [this](){ this->camera.transform->rotate(glm::vec3(0.0f, 0.0f, 0.5f)); }}
        };


        Camera& getCamera() {return camera;}
        static inline InputSystem& getInstance() { return instance;}
};


void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void processInput(GLFWwindow* window, float deltaTime);