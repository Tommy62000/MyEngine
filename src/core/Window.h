#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose();
    void pollEvents();
    void swapBuffers();

    GLFWwindow* getNativeWindow();

private:
    GLFWwindow* window;
};