#include "Shader.h"
#include "../core/log/Logger.h"
#include <fstream>
#include <sstream>
#include <iostream>

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