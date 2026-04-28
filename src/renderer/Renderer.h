#pragma once
#include "Shader.h"
#include "../core/Mesh.h"

#include <memory>

class Renderer {
public:
    Renderer();
    void init();
    void clear();
    void draw();

private:
    unsigned int VAO, VBO;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Mesh> triangleMesh;
};