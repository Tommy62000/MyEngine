#pragma once

#include <vector>
#include <memory>
#include "Mesh.h"
#include "DirectionalLight.h"


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

    /**
     * @brief Adds a directional light to the scene.
     *
     * The light is copied into the internal container and will be used
     * during rendering for lighting calculations.
     *
     * @param light DirectionalLight instance to add.
     */
    void addDirectionalLight(const DirectionalLight& light);

    /**
     * @brief Retrieves all directional lights in the scene.
     *
     * Provides read-only access to the internal list of directional lights.
     *
     * @return Constant reference to a vector of DirectionalLight objects.
     *
     * @warning The returned reference does not allow modification of the container,
     * but the Light objects themselves may still be mutable if not enforced otherwise.
     */
    const std::vector<DirectionalLight>& getDirectionalLights() const;

private:
    std::vector<std::unique_ptr<Mesh>> meshes;
    std::vector<DirectionalLight> directionalLights;
};