#include "Renderer.h"
#include "../core/AssetManager.h"
#include <glad/glad.h>

Renderer::Renderer() {}

void Renderer::init() {
    // Load shaders
    shader = std::make_unique<Shader>(
        AssetManager::shader("basic.vert"),
        AssetManager::shader("basic.frag")
    );

    // Create the Mesh
    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    std::vector<unsigned int> indices = {
        0, 1, 2
    };

    triangleMesh = std::make_unique<Mesh>(vertices, indices);
}

void Renderer::clear() {
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw() {
    shader->use();
    glBindVertexArray(VAO);
    triangleMesh->draw();
}