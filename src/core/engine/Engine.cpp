#include "Engine.h"
#include <filesystem>

std::string Engine::s_root = "";

void Engine::init(const std::string& projectRoot) {
    if (!projectRoot.empty()) {
        s_root = projectRoot;
        return;
    }

    std::filesystem::path exeDir = std::filesystem::current_path();
    std::filesystem::path projectRootPath = exeDir.parent_path();

    s_root = projectRootPath.string(); // <-- SOLO ROOT
}

const std::string& Engine::root() {
    return s_root;
}

std::string Engine::assetPath(const std::string& relativePath) {
    return (std::filesystem::path(s_root) / "assets" / relativePath).string();
}