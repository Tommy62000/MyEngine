#include "AssetManager.h"
#include "Engine.h"

std::string AssetManager::shader(const std::string& file) {
    return Engine::root() + "/assets/shaders/" + file;
}