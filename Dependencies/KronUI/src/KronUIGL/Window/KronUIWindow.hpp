#ifndef GLFWXWindow_guard
#define GLFWXWindow_guard

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <string>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class KronUIWindow{
private:
    std::string _name;
    GLFWwindow* _self;
public:
    unsigned int VAO, VBO;
    unsigned int _width = 800;
    unsigned int _height = 600;
    KronUIWindow(std::string name, int width, int height);
    std::string getName() {return _name;}
    GLFWwindow* getSelf(){return _self;}
};


class KronUIWindowManager{
private:
    static KronUIWindow* _window;
public:
    static KronUIWindow* getWindow(){return _window;}
    static void setWindow(KronUIWindow* window){_window = window;}
};

#endif