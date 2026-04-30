#include "Camera.h"
#include <glm/gtc/constants.hpp>

Camera::Camera(glm::vec3 C,
               glm::vec3 worldUp,
               float yaw,
               float pitch)
{
    this->C = C;
    this->worldUp = worldUp;

    this->yaw = yaw;
    this->pitch = pitch;

    u_f = glm::vec3(0.0f, 0.0f, -1.0f);

    updateCameraVectors();
}

void Camera::setFov(float newFov) {
    fov = newFov;

    // Clamp
    if (fov < 1.0f) fov = 1.0f;
    if (fov > 120.0f) fov = 120.0f;
}

void Camera::setAspectRatio(float newAspectRatio) {
    aspectRatio = newAspectRatio;
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(C, C + u_f, u_u);
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return glm::perspective(
        glm::radians(fov),
        aspectRatio,
        nearPlane,
        farPlane
    );
}

void Camera::updateCameraVectors()
{
    // Build forward vector
    glm::vec3 f;

    f.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    f.y = sin(glm::radians(pitch));
    f.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    // Obtain the base
    u_f = glm::normalize(f);
    u_r = glm::normalize(glm::cross(u_f, worldUp));
    u_u = glm::normalize(glm::cross(u_r, u_f));
}