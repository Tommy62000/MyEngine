#pragma once

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Mesh {
public:
    Mesh(const std::vector<float>& vertices,
        const std::vector<unsigned int>& indices);
    ~Mesh();

    void draw() const;

    // Transform
    glm::vec3 position {0.0f};
    glm::vec3 rotation {0.0f}; // gradi
    glm::vec3 scale    {1.0f};

    glm::mat4 getModelMatrix() const;

private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int indexCount;
};