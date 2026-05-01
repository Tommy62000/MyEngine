#pragma once

#include <glm/glm.hpp>

/**
 * @brief Represents a directional light source.
 *
 * A directional light simulates a light source at an infinite distance,
 * where all light rays are parallel. It is commonly used to represent
 * sunlight or moonlight in a scene.
 */
class DirectionalLight {
public:
    /**
     * @brief Direction of the light.
     *
     * Defines the direction from which the light is coming.
     * The vector should typically be normalized.
     */
    glm::vec3 direction { -0.3f, -1.0f, -0.2f };

    /**
     * @brief Color of the light.
     *
     * Represents the RGB intensity of the light source.
     */
    glm::vec3 color { 1.0f, 1.0f, 1.0f };

    /**
     * @brief Default constructor.
     *
     * Initializes the light with default direction and white color.
     */
    DirectionalLight() = default;

    /**
     * @brief Constructs a directional light with custom parameters.
     *
     * @param dir Direction of the light.
     * @param col Color (intensity) of the light.
     */
    DirectionalLight(const glm::vec3& dir, const glm::vec3& col)
        : direction(dir), color(col) {}
};