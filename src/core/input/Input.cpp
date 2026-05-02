#include "Input.h"
#include <cstring>

GLFWwindow* Input::window = nullptr;

bool Input::keys[512] = { false };

double Input::lastX = 0.0;
double Input::lastY = 0.0;
double Input::deltaX = 0.0;
double Input::deltaY = 0.0;
bool Input::firstMouse = true;

CursorMode Input::cursorMode = CursorMode::Locked;

void Input::Init(GLFWwindow* win) {
    window = win;

    glfwSetCursorPosCallback(window, MouseCallback);

    SetCursorMode(CursorMode::Locked);
}

void Input::Update() {
    for (int i = 0; i < 512; i++) {
        keys[i] = glfwGetKey(window, i) == GLFW_PRESS;
    }
}

bool Input::IsKeyPressed(int key) {
    return keys[key];
}

glm::vec2 Input::GetMouseDelta() {
    glm::vec2 d(deltaX, deltaY);

    deltaX = 0;
    deltaY = 0;

    return d;
}

void Input::SetCursorMode(CursorMode mode) {
    cursorMode = mode;

    if (mode == CursorMode::Locked) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        firstMouse = true;
        deltaX = 0;
        deltaY = 0;

    } else {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

void Input::ResetMouse() {
    firstMouse = true;
    deltaX = 0;
    deltaY = 0;
}

void Input::MouseCallback(GLFWwindow* win, double xpos, double ypos) {

    if (cursorMode == CursorMode::Normal)
        return;

    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;

        deltaX = 0;
        deltaY = 0;
        return;
    }

    deltaX = xpos - lastX;
    deltaY = lastY - ypos;

    lastX = xpos;
    lastY = ypos;
}

