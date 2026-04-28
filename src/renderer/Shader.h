#pragma once

#include <string>
#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;

    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    void use();

private:
    std::string loadFile(const std::string& path);
    unsigned int compile(unsigned int type, const std::string& source);
};