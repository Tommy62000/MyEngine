#pragma once

#include "Shader.h"
#include "../core/Mesh.h"
#include "../core/Camera.h"

#include <memory>

class Scene;

class Renderer {
public:
    Renderer();
    void init();
    void clear();

    void draw(const Scene& scene, const Camera& camera);

private:
    std::unique_ptr<Shader> shader;
};