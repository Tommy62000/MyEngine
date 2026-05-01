#pragma once
#include <string>

/**
 * @brief Global engine utility class.
 *
 * The Engine class provides access to engine-wide configuration
 * and utility functions such as project root handling and asset path resolution.
 * It is designed as a static-only class.
 */
class Engine {
public:
    /**
     * @brief Initializes the engine with the project root directory.
     *
     * This function must be called before using any other Engine functionality.
     *
     * @param projectRoot Absolute or relative path to the root of the project.
     */
    static void init(const std::string& projectRoot);

    /**
     * @brief Retrieves the engine root directory.
     *
     * @return Constant reference to the stored root path.
     */
    static const std::string& root();

    /**
     * @brief Builds an absolute path to an asset.
     *
     * Concatenates the engine root path with a relative asset path.
     *
     * @param relativePath Path relative to the project root.
     * @return Full resolved path to the asset.
     */
    static std::string assetPath(const std::string& relativePath);
    
private:
    static std::string s_root;
};