#pragma once

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
public:
    unsigned int ID;

    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    void use();

    void setMat4(const std::string& name, const glm::mat4& mat) const;
private:
    std::string loadFile(const std::string& path);
    unsigned int compile(unsigned int type, const std::string& source);
};