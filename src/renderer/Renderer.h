#pragma once

#include "Shader.h"
#include "../core/Mesh.h"
#include "../core/Camera.h"

#include <memory>

class Scene;

/**
 * @class Renderer
 * @brief Responsible for rendering a scene using a camera and shader pipeline.
 *
 * The Renderer is the core of the rendering system.
 * It takes a Scene and a Camera and produces a final image by:
 * - binding shaders
 * - setting uniforms (view/projection matrices)
 * - issuing draw calls for all meshes in the scene
 */
class Renderer {
public:
    /**
     * @brief Constructs the renderer.
     *
     * Initializes internal rendering resources such as shaders.
     */
    Renderer();

    /**
     * @brief Initializes rendering state.
     *
     * Sets up GPU state, loads shaders and prepares the renderer for drawing.
     * Must be called before any draw operation.
     */
    void init();

    /**
     * @brief Clears the rendering buffers.
     *
     * Clears color and depth buffers at the beginning of a frame.
     */
    void clear();

    /**
     * @brief Renders a complete scene from the perspective of a camera.
     *
     * This function performs the full rendering pipeline:
     * 1. Activates the shader program
     * 2. Uploads camera view and projection matrices
     * 3. Iterates over all scene objects
     * 4. Applies model transformations
     * 5. Issues draw calls for each mesh
     *
     * @param scene Scene containing all renderable objects
     * @param camera Camera defining view and projection matrices
     */
    void draw(const Scene& scene, const Camera& camera);

private:
    std::unique_ptr<Shader> shader;
};