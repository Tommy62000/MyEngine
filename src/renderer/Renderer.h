#pragma once
#include "Shader.h"
#include "../core/Mesh.h"

#include <memory>
#include <vector>

class Renderer {
public:
    Renderer();
    void init();
    void clear();
    void draw();

    void submit(Mesh& mesh);

private:
    unsigned int VAO, VBO;
    std::unique_ptr<Shader> shader;
    std::vector<Mesh*> renderQueue;
};