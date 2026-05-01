#pragma once

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/**
 * @class Mesh
 * @brief Represents a renderable 3D mesh stored on the GPU.
 *
 * A mesh encapsulates:
 * - Vertex data (VBO)
 * - Index data (EBO)
 * - Vertex array configuration (VAO)
 *
 * It is responsible for storing geometry in GPU memory and issuing draw calls.
 */
class Mesh {
public:
    /**
     * @brief Creates a mesh from raw vertex and index data.
     *
     * Uploads vertex data to the GPU and configures the VAO/VBO/EBO layout
     * required for rendering.
     *
     * @param vertices Interleaved vertex data (position, normals, etc.)
     * @param indices Index buffer defining triangle connectivity
     */
    Mesh(const std::vector<float>& vertices,
        const std::vector<unsigned int>& indices);
    
    /**
     * @brief Releases GPU resources associated with the mesh.
     *
     * Deletes VAO, VBO, and EBO from GPU memory.
     */
    ~Mesh();

    /**
     * @brief Renders the mesh.
     *
     * Binds the VAO and issues a draw call using indexed rendering.
     *
     * Assumes that a valid shader program is already active.
     */
    void draw() const;

    // Transform
    glm::vec3 position {0.0f}; ///< WCS position of the mesh
    glm::vec3 rotation {0.0f}; ///< Rotation [degrees]
    glm::vec3 scale    {1.0f}; ///< Scale factor

    /**
     * @brief Computes the model transformation matrix.
     *
     * Combines translation, rotation, and scaling into a single matrix
     * that transforms object space into world space.
     *
     * Order of transformations:
     * 1. Scale
     * 2. Rotate (Z -> Y -> X or implementation-defined)
     * 3. Translate
     *
     * @return glm::mat4 Model matrix
     */
    glm::mat4 getModelMatrix() const;

private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int indexCount;
};