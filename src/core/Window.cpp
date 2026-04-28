#include "Window.h"
#include "log/Logger.h"
#include <iostream>

Window::Window(int width, int height, const char* title) {
    if (!glfwInit()) {
        Logger::Error("Failed to init GLFW\n");
        return;
    }
    // Request OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Use the Core Profile (no deprecated OpenGL features)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif
    // Create a window and its associated OpenGL context using GLFW
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        Logger::Error("Failed to create window\n");
        glfwTerminate();
        return;
    }
    // Make the OpenGL context of this window current on the calling thread
    glfwMakeContextCurrent(window);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}

GLFWwindow* Window::getNativeWindow() {
    return window;
}