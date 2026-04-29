#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    // State
    glm::vec3 C;

    glm::vec3 u_f;
    glm::vec3 u_u;
    glm::vec3 u_r;
    glm::vec3 worldUp;

    // Angles to build forward vector
    float yaw;
    float pitch;

    Camera(glm::vec3 C = glm::vec3(0.0f, 0.0f, 3.0f),
           glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
           float yaw = -90.0f,
           float pitch = 0.0f);

    // View matrix
    glm::mat4 getViewMatrix() const;

    // Update camera vectors
    void updateCameraVectors();
};