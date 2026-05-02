#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

/**
 * @enum CursorMode
 * @brief Defines the current mouse cursor behavior mode.
 *
 * - Normal: Cursor is visible and free to move outside the window.
 * - Locked: Cursor is hidden and captured for FPS-style camera control.
 */
enum class CursorMode {
    Normal,
    Locked
};

/**
 * @class Input
 * @brief Static input system wrapper around GLFW.
 *
 * Provides keyboard state polling and mouse delta tracking.
 * Designed as a global input manager for the engine.
 *
 * Handles:
 * - Keyboard input (WASD, actions, etc.)
 * - Mouse movement (delta-based FPS camera control)
 * - Cursor mode switching (normal / locked)
 */
class Input {
public:
    /**
     * @brief Initializes the input system.
     *
     * Registers GLFW callbacks and binds the window context.
     *
     * @param window Pointer to the GLFW window
     */
    static void Init(GLFWwindow* window);

    /**
     * @brief Updates the input state for the current frame.
     *
     * Polls keyboard states and resets per-frame mouse deltas.
     * Must be called once per frame before using input data.
     */
    static void Update();

    /**
     * @brief Checks if a key is currently pressed.
     *
     * @param key GLFW key code
     * @return true if the key is pressed, false otherwise
     */
    static bool IsKeyPressed(int key);

    /**
     * @brief Returns the mouse movement delta since last frame.
     *
     * Used for camera rotation in FPS-style controls.
     *
     * @return 2D vector containing (x, y) mouse movement
     */
    static glm::vec2 GetMouseDelta();

    /**
     * @brief Sets the cursor mode (locked or normal).
     *
     * Locked mode hides and captures the cursor for FPS control.
     * Normal mode releases the cursor.
     *
     * @param mode Desired cursor mode
     */
    static void SetCursorMode(CursorMode mode);

    /**
     * @brief Resets mouse internal state.
     *
     * Useful when switching cursor modes to avoid large delta spikes.
     */
    static void ResetMouse();

private:
    static GLFWwindow* window;

    static bool keys[512];

    static double lastX;
    static double lastY;
    static double deltaX;
    static double deltaY;
    static bool firstMouse;

    static CursorMode cursorMode;

    /**
     * @brief GLFW mouse position callback.
     *
     * Captures raw cursor movement and computes frame delta.
     *
     * @param window GLFW window pointer
     * @param xpos Current mouse X position
     * @param ypos Current mouse Y position
     */
    static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
};