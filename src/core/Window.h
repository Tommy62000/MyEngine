#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

/**
 * @brief Encapsulates a GLFW window and its basic lifecycle.
 *
 * The Window class is a thin wrapper around a GLFWwindow pointer.
 * It manages window creation, event polling, and buffer swapping.
 */
class Window {
public:
    /**
     * @brief Constructs a window with the given size and title.
     *
     * Initializes a GLFW window and prepares it for rendering.
     *
     * @param width Width of the window in pixels.
     * @param height Height of the window in pixels.
     * @param title Title of the window.
     */
    Window(int width, int height, const char* title);

    /**
     * @brief Destroys the window and releases GLFW resources.
     */
    ~Window();

    /**
     * @brief Checks whether the window should close.
     *
     * Typically used in the main loop condition.
     *
     * @return true if the window has been requested to close, false otherwise.
     */
    bool shouldClose();

    /**
     * @brief Polls window events.
     *
     * Processes input, window events, and system messages.
     */
    void pollEvents();

    /**
     * @brief Swaps the front and back buffers.
     *
     * Presents the rendered frame to the screen.
     */
    void swapBuffers();

    /**
     * @brief Retrieves the underlying GLFW window pointer.
     *
     * @return Raw pointer to the GLFWwindow instance.
     *
     * @warning Exposing the native pointer allows direct GLFW access,
     * bypassing the Window abstraction.
     */
    GLFWwindow* getNativeWindow();

private:
    GLFWwindow* window;
};