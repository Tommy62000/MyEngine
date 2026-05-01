#pragma once

#include <vector>
#include <memory>
#include "Mesh.h"

/**
 * @brief Represents a collection of renderable meshes.
 *
 * The Scene class owns and manages a set of Mesh objects.
 * Ownership is exclusive and handled via std::unique_ptr.
 */
class Scene {
public:
    /**
     * @brief Adds a mesh to the scene.
     *
     * Transfers ownership of the given mesh to the Scene.
     * After the call, the caller no longer owns the mesh.
     *
     * @param mesh Unique pointer to the Mesh to add. Must be passed with std::move.
     *
     * @note The input pointer becomes null after the call.
     */
    void addMesh(std::unique_ptr<Mesh> mesh);

    /**
     * @brief Retrieves all meshes in the scene.
     *
     * Provides read-only access to the internal container.
     * The structure of the container cannot be modified, but
     * the Mesh objects themselves may still be mutable.
     *
     * @return Constant reference to the vector of meshes.
     *
     * @warning Modifying the returned Mesh objects may affect the Scene state.
     */
    const std::vector<std::unique_ptr<Mesh>>& getMeshes() const;

private:
    std::vector<std::unique_ptr<Mesh>> meshes;
};