#pragma once
#include "core/Window.h"
#include "Shader.h"

class Renderer {
public:
    Renderer();
    void init();
    void clear();
    void drawTriangle();

private:
    unsigned int VAO, VBO;
    Shader* shader;
};