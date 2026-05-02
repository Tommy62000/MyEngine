#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <filesystem>

#include "core/Window.h"
#include "core/Scene.h"
#include "core/Camera.h"
#include "core/engine/Engine.h"
#include "core/input/Input.h"
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

    // Create the input system
    Input::Init(window.getNativeWindow());

    // Create the renderer
    Renderer renderer;
    renderer.init();
    Logger::Info("Renderer started");

    // Create the camera
    Camera camera;
    camera.updateCameraVectors();

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

    float lastFrame = 0.0f;

    while (!window.shouldClose()) {

        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        GLFWwindow* win = window.getNativeWindow();

        window.pollEvents();
        Input::Update();

        static bool escPrev = false;
        static bool locked = true;

        bool esc = Input::IsKeyPressed(GLFW_KEY_ESCAPE);

        if (esc && !escPrev) {
            locked = !locked;

            Input::SetCursorMode(
                locked ? CursorMode::Locked : CursorMode::Normal
            );

            Input::ResetMouse();
        }

        escPrev = esc;

        if (Input::IsKeyPressed(GLFW_KEY_W))
            camera.processKeyboard(GLFW_KEY_W, deltaTime);

        if (Input::IsKeyPressed(GLFW_KEY_S))
            camera.processKeyboard(GLFW_KEY_S, deltaTime);

        if (Input::IsKeyPressed(GLFW_KEY_A))
            camera.processKeyboard(GLFW_KEY_A, deltaTime);

        if (Input::IsKeyPressed(GLFW_KEY_D))
            camera.processKeyboard(GLFW_KEY_D, deltaTime);

        glm::vec2 mouse = Input::GetMouseDelta();
        camera.processMouseMovement(mouse.x, mouse.y);

        renderer.clear();
        renderer.draw(scene, camera);

        window.swapBuffers();
    }
}