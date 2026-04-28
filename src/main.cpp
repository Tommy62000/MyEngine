#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <filesystem>

#include "core/Window.h"
#include "core/Engine.h"
#include "core/AssetManager.h"
#include "core/log/Logger.h"
#include "renderer/Renderer.h"

int main() {
    Logger::Init();

    Engine::init(std::filesystem::current_path().parent_path().string());
    Logger::Info(std::string("ENGINE ROOT = ") + Engine::root());
    Logger::Info(std::string("ASSET PATH = ") + Engine::assetPath(""));
    Logger::Info("Engine started");

    Window window(800, 600, "MyEngine");

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    Renderer renderer;
    renderer.init();

    while (!window.shouldClose()) {
        renderer.clear();
        renderer.draw();

        window.swapBuffers();
        window.pollEvents();
    }
}