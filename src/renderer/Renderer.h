#pragma once

#include "Shader.h"
#include "../core/Mesh.h"

#include <memory>

class Scene;

class Renderer {
public:
    Renderer();
    void init();
    void clear();

    void draw(const Scene& scene);

private:
    std::unique_ptr<Shader> shader;
};