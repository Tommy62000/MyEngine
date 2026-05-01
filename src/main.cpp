#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <filesystem>

#include "core/Window.h"
#include "core/Scene.h"
#include "core/Camera.h"
#include "core/engine/Engine.h"
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
    Logger::Info("Renderer started");

    // Create the camera
    Camera camera;

    // Obtain window aspect ratio
    int width, height;
    glfwGetFramebufferSize(window.getNativeWindow(), &width, &height);
    camera.setAspectRatio((float) width / (float) height);

    // Create the example scene
    Scene scene;

    scene.addDirectionalLight(
        DirectionalLight(
            glm::vec3(-0.3f, -1.0f, -0.2f),
            glm::vec3(1.0f, 1.0f, 1.0f)
        )
    );

    // Test triangle
    std::vector<float> vertices = {
        // position            // normal
        -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,
        0.0f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f
    };

    std::vector<unsigned int> indices = {
        0, 1, 2
    };

    // Test triangle 2
    std::vector<float> vertices2 = {
        // position             // normal
        0.5f,  0.5f, -1.0f,    0.0f, 0.0f, -1.0f,
        -0.5f,  0.5f, -1.0f,    0.0f, 0.0f, -1.0f,
        0.0f, -0.5f, -1.0f,    0.0f, 0.0f, -1.0f
    };
    
    scene.addMesh(std::make_unique<Mesh>(vertices, indices));
    scene.addMesh(std::make_unique<Mesh>(vertices2, indices));

    while (!window.shouldClose()) {
        renderer.clear();
        renderer.draw(scene, camera);

        window.swapBuffers();
        window.pollEvents();
    }
}