#pragma once
#include <string>

/**
 * @brief Utility class for resolving asset paths.
 *
 * AssetManager provides helper functions to construct paths
 * to engine resources such as shaders, textures, and other assets.
 * It is designed as a static-only utility class.
 */
class AssetManager {
public:
    /**
     * @brief Returns the full path to a shader file.
     *
     * Constructs a valid path to a shader resource based on the
     * engine's asset directory structure.
     *
     * @param file Name of the shader file (relative path or filename).
     * @return Full resolved path to the shader file.
     */
    static std::string shader(const std::string& file);
};