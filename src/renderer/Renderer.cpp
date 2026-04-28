#include "Renderer.h"
#include "../core/AssetManager.h"
#include <glad/glad.h>

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

Renderer::Renderer() {}

void Renderer::init() {
    shader = std::make_unique<Shader>(
        AssetManager::shader("basic.vert"),
        AssetManager::shader("basic.frag")
    );

    // Generate a Vertex Array Object (stores vertex attribute configuration)
    glGenVertexArrays(1, &VAO);
    // Generate a Vertex Buffer Object (stores vertex data in GPU memory)
    glGenBuffers(1, &VBO);
    // Bind the VAO (all subsequent vertex attribute calls will be stored here)
    glBindVertexArray(VAO);
    // Bind the VBO to GL_ARRAY_BUFFER (this becomes the active vertex buffer)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Upload data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // Define the layout of the vertex data (attribute 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    // Enable the vertex attribute (location = 0)
    glEnableVertexAttribArray(0);
}

void Renderer::clear() {
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawTriangle() {
    shader->use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}