#pragma once
#include "core/Window.h"
#include "Shader.h"

#include <memory>

class Renderer {
public:
    Renderer();
    void init();
    void clear();
    void drawTriangle();

private:
    unsigned int VAO, VBO;
    std::unique_ptr<Shader> shader;
};