#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Window.h"
#include "core/Engine.h"
#include "core/AssetManager.h"
#include "core/log/Logger.h"
#include "renderer/Renderer.h"

int main() {
    Logger::Init();

    Engine::init("/Users/tommasoleoni/Documents/Programmazione/Progetti lavoro/MyEngine");
    Logger::Info("Engine started");

    Window window(800, 600, "MyEngine");

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Renderer renderer;
    renderer.init();

    while (!window.shouldClose()) {
        renderer.clear();
        renderer.drawTriangle();

        window.swapBuffers();
        window.pollEvents();
    }
}