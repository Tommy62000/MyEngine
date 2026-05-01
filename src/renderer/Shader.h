#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

/**
 * @brief Encapsulates an OpenGL shader program.
 *
 * The Shader class handles loading, compiling, and linking
 * vertex and fragment shaders into a single GPU program.
 * It also provides utility functions for setting uniform values.
 */
class Shader {
public:
    /**
     * @brief OpenGL program ID.
     *
     * This is the identifier of the compiled and linked shader program
     * used internally by OpenGL.
     */
    unsigned int ID;

    /**
     * @brief Creates a shader program from vertex and fragment shader files.
     *
     * Loads shader source code from the provided file paths, compiles them,
     * and links them into a single OpenGL shader program.
     *
     * @param vertexPath Path to the vertex shader source file.
     * @param fragmentPath Path to the fragment shader source file.
     */
    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    /**
     * @brief Activates the shader program.
     *
     * Makes this shader the current active program for rendering.
     */
    void use();

    /**
     * @brief Sets a 4x4 matrix uniform in the shader.
     *
     * @param name Name of the uniform variable in the shader.
     * @param mat 4x4 matrix value to upload.
     */
    void setMat4(const std::string& name, const glm::mat4& mat) const;
    
    /**
     * @brief Sets a vec3 uniform in the shader.
     *
     * Updates the value of a vec3 uniform variable in the currently active
     * shader program.
     *
     * @param name Name of the uniform variable in the GLSL shader.
     * @param value glm::vec3 value to upload to the GPU.
     */
    void setVec3(const std::string& name, const glm::vec3& value) const;
private:
    std::string loadFile(const std::string& path);
    unsigned int compile(unsigned int type, const std::string& source);
};