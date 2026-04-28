#include "Engine.h"

std::string Engine::s_root = "";

void Engine::init(const std::string& projectRoot) {
    s_root = projectRoot;
}

const std::string& Engine::root() {
    return s_root;
}