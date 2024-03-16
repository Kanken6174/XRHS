#include "./KronUIWindow.hpp"
#include <iostream>

KronUIWindow* KronUIWindowManager::_window;

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    if(KronUIWindowManager::getWindow() == nullptr) return; 
    KronUIWindowManager::getWindow()->_height = height;
    KronUIWindowManager::getWindow()->_width = width;
}

KronUIWindow::KronUIWindow(std::string name, int width = 0, int height = 0) : _name(name), _width(width), _height(height){
    // glfw: initialize and configure
    // ------------------------------
    std::cout << "GLfw init" << glfwInit() << std::endl;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
   // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    std::cout << "GLfw init done" << std::endl;


    if(_width == 0 || _height == 0){
        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        _width = mode->width;
        _height = mode->height;
    }


    // glfw window creation
    // --------------------
    _self = glfwCreateWindow(_width, _height, name.c_str(), NULL, NULL);
    if (_self == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(_self);
    std::cout << "set context" << std::endl;
    glewInit();
    glfwSetFramebufferSizeCallback(_self, framebuffer_size_callback);
    glfwSetInputMode(_self, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    std::cout << "set framebuffer size callback" << std::endl;
    glViewport(0, 0, 640, 480);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    std::cout << "loaded identity" << std::endl;
    // OpenGL state
    // ------------
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    std::cout << "set opengl states" << std::endl;
    // configure VAO/VBO for texture quads
    // -----------------------------------

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    std::cout << "configured VAO VBOs" << std::endl;
}
