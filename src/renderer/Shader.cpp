#include "Shader.h"
#include "../core/log/Logger.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexCode = loadFile(vertexPath);
    std::string fragmentCode = loadFile(fragmentPath);

    unsigned int vertex = compile(GL_VERTEX_SHADER, vertexCode);
    unsigned int fragment = compile(GL_FRAGMENT_SHADER, fragmentCode);

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    int success;
    glGetProgramiv(ID, GL_LINK_STATUS, &success);

    if (!success) {
        char log[512];
        glGetProgramInfoLog(ID, 512, nullptr, log);
        Logger::Error(std::string("Shader link error:\n") + log);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
    int location = glGetUniformLocation(ID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
    int location = glGetUniformLocation(ID, name.c_str());
    glUniform3fv(location, 1, &value[0]);
}

std::string Shader::loadFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream stream;

    if (!file.is_open()) {
        Logger::Error(std::string("Failed to open shader: ") + path);
        return "";
    }

    stream << file.rdbuf();
    return stream.str();
}

unsigned int Shader::compile(unsigned int type, const std::string& source) {
    unsigned int shader = glCreateShader(type);
    const char* src = source.c_str();

    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        Logger::Error(std::string("Shader compile error:\n") + log);
    }

    return shader;
}