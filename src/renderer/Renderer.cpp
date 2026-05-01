#include "Renderer.h"
#include "../core/Scene.h"
#include "../core/engine/AssetManager.h"
#include <glad/glad.h>

Renderer::Renderer() {}

void Renderer::init() {
    // Load shaders
    shader = std::make_unique<Shader>(
        AssetManager::shader("basic.vert"),
        AssetManager::shader("basic.frag")
    );
}

void Renderer::clear() {
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Scene& scene, const Camera& camera) {
    // Use shaders
    shader->use();

    // Obtain the camera matrix and the projection matrix
    glm::mat4 view = camera.getViewMatrix();
    glm::mat4 projection = camera.getProjectionMatrix();

    // Load the matrices in the shaders
    shader->setMat4("view", view);
    shader->setMat4("projection", projection);

    // Load the lights from the scene in the shaders
    const auto& lights = scene.getDirectionalLights();

    if (!lights.empty()) {
        // Right now only a single light
        const auto& light = lights[0];

        shader->setVec3("lightDir", light.direction);
        shader->setVec3("lightColor", light.color);
    }

    // Load the meshes from the scene in the shaders
    for (const auto& mesh : scene.getMeshes()) {
        // Obtain model matrix
        glm::mat4 model = mesh->getModelMatrix();

        // Load the model matrix in the shaders
        shader->setMat4("model", model);

        // Load the model colors in the shaders
        shader->setVec3("objectColor", glm::vec3(1.0f, 0.0f, 0.0f));

        // Render using shaders
        mesh->draw();
    }
}