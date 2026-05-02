#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/**
 * @class Camera
 * @brief A 3D camera
 * 
 * A 3D camera which contains:
 * - position
 * - orientation
 * - projection parameters
 */
class Camera {
public:
    // STATE PARAMETERS
    glm::vec3 C; ///< The camera position in the WCS
    glm::vec3 worldUp; ///< Vertical versor in the WCS
    float yaw; ///< The camera rotation around its vertical axis [degrees]
    float pitch; ///< The camera rotation around its horizontal axis [degrees]

    // Helper methods for state parameters
    /**
     * @brief Sets the camera position in WCS.
     *
     * Updates the camera position and marks the internal orientation
     * as potentially outdated.
     *
     * @param newPosition New camera position in world space
     */
    void setPosition(const glm::vec3& newPosition);

    /**
     * @brief Sets the world up vector.
     *
     * Defines the global up direction used to build the camera basis.
     * Changing this affects the orientation computation.
     *
     * @param newWorldUp New world up vector (must not be zero)
     */
    void setWorldUp(const glm::vec3& newWorldUp);

    /**
     * @brief Sets the camera yaw angle.
     *
     * Defines the horizontal rotation around the world up axis (Y axis).
     * This affects the camera's left/right viewing direction.
     *
     * @param newYaw New yaw angle [degrees]
     */
    void setYaw(float newYaw);

    /**
     * @brief Sets the camera pitch angle.
     *
     * Defines the vertical rotation around the camera right axis (X axis).
     * Controls the up/down viewing direction.
     *
     * Pitch is typically clamped to avoid gimbal lock and unstable behavior.
     *
     * @param newPitch New pitch angle [degrees]
     */
    void setPitch(float newPitch);

    // PROJECTION PARAMETERS
    float fov = 60.0f; ///< The camera vertical fov (OpenGL standard) [degrees]
    float aspectRatio = 16.0f / 9.0f; ///< The viewport aspect ratio
    float nearPlane = 0.1f; ///< Near clipping plane distance
    float farPlane = 100.0f; ///< Far clipping plane distance

    // Helper methods for the projection parameters
    /**
     * @brief Sets the vertical field of view.
     *
     * @param newFov Field of view in degrees (clamped to avoid extreme distortion)
     */
    void setFov(float newFov);

    /**
     * @brief Sets the aspect ratio of the viewport.
     *
     * @param newAspectRatio Width / height ratio (must be > 0)
     */
    void setAspectRatio(float newAspectRatio);

    /**
     * @brief Sets near clipping plane distance.
     *
     * @param newNearPlane Must be > 0 and < farPlane
     */
    void setNearPlane(float newNearPlane);

    /**
     * @brief Sets far clipping plane distance.
     *
     * @param newFarPlane Must be > nearPlane
     */
    void setFarPlane(float newFarPlane);

    // MOVEMENT PARAMETERS
    float movementSpeed = 3.0f; ///< Movement speed of the camera in world space
    float mouseSensitivity = 0.1f; ///< Mouse sensitivity multiplier for camera rotation
    
    /**
     * @brief Sets the camera movement speed.
     *
     * Defines how fast the camera moves through world space when
     * processing keyboard input (e.g., WASD movement).
     *
     * The final movement speed is typically scaled by delta time
     * to ensure frame-rate independent motion.
     *
     * @param newMovementSpeed New movement speed value (units per second)
     */
    void setMovementSpeed(float newMovementSpeed);

    /**
     * @brief Sets the mouse sensitivity for camera rotation.
     *
     * Controls how strongly mouse movement affects yaw and pitch changes.
     * Higher values result in faster camera rotation for the same mouse delta.
     *
     *
     * @param newMouseSensitivity New sensitivity multiplier for mouse input
     */
    void setMouseSensitivity(float newMouseSensitivity);

    /**
     * @brief Constructs a 3D camera.
     *
     * Initializes the camera in world space with a given position and orientation.
     * The orientation is defined using yaw (horizontal rotation) and pitch (vertical rotation).
     *
     * @param C Initial position of the camera in world space
     * @param worldUp World up direction used as reference for camera basis construction
     * @param yaw Initial horizontal rotation (in degrees)
     * @param pitch Initial vertical rotation (in degrees)
     *
     * @note After construction, camera direction vectors are computed automatically.
     */
    Camera(glm::vec3 C = glm::vec3(0.0f, 0.0f, 1.0f),
           glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
           float yaw = -90.0f,
           float pitch = 0.0f);

    /**
     * @brief Computes the view matrix of the camera.
     *
     * The view matrix transforms WCS into CCS.
     * It is built using the camera position and its orientation vectors.
     *
     * @return glm::mat4 View matrix transforming world space to camera space
     *
     * @note Uses a right-handed coordinate system (OpenGL convention)
     */
    glm::mat4 getViewMatrix() const;

    /**
     * @brief Computes the projection matrix of the camera.
     *
     * Builds a perspective projection matrix using the camera parameters:
     * field of view, aspect ratio, and near/far clipping planes.
     *
     * This matrix transforms view space coordinates into clip space.
     *
     * @return glm::mat4 Perspective projection matrix
     *
     * @note Uses OpenGL convention with depth range [-1, 1]
     */
    glm::mat4 getProjectionMatrix() const;

    /**
     * @brief Recomputes the camera orientation vectors.
     *
     * Updates the forward, right, and up vectors based on the current yaw and pitch.
     * This ensures that the camera basis remains orthonormal.
     *
     * Must be called after modifying yaw or pitch.
     *
     * @note This function maintains a right-handed coordinate system.
     */
    void updateCameraVectors();

    /**
     * @brief Processes keyboard input for camera movement.
     *
     * Updates the camera position based on the given key input.
     * Typically used with WASD controls to move the camera in world space.
     *
     * Movement is scaled by deltaTime to ensure frame-rate independent motion.
     *
     * @param key GLFW key code representing the pressed key
     * @param deltaTime Time elapsed since the last frame (in seconds)
     */
    void processKeyboard(int key, float deltaTime);

    /**
     * @brief Processes mouse movement input for camera rotation.
     *
     * Updates the camera yaw and pitch based on mouse movement offsets.
     * This is typically used for FPS-style camera control.
     *
     * The offsets are usually scaled by a mouse sensitivity factor.
     *
     * @param xoffset Horizontal mouse movement since last frame
     * @param yoffset Vertical mouse movement since last frame
     */
    void processMouseMovement(float xoffset, float yoffset);

private:
    glm::vec3 u_f;
    glm::vec3 u_u;
    glm::vec3 u_r;
};