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

void Renderer::draw(const Scene& scene) {
    shader->use();

    for (const auto& mesh : scene.getMeshes()) {
        mesh->draw();
    }
}