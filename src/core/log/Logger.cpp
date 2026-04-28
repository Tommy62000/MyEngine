#include "Logger.h"
#include <string>
#include <iostream>

void Logger::Init()
{
    std::cout << "[Logger] Initialized\n";
}

void Logger::Log(LogLevel level, const std::string& message)
{
    std::cout << "[" << LevelToString(level) << "] " << message << std::endl;
}

void Logger::Info(const std::string& message)
{
    Log(LogLevel::Info, message);
}

void Logger::Warning(const std::string& message)
{
    Log(LogLevel::Warning, message);
}

void Logger::Error(const std::string& message)
{
    Log(LogLevel::Error, message);
}

void Logger::Debug(const std::string& message)
{
    Log(LogLevel::Debug, message);
}

std::string Logger::LevelToString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::Info: return "INFO";
        case LogLevel::Warning: return "WARN";
        case LogLevel::Error: return "ERROR";
        case LogLevel::Debug: return "DEBUG";
    }
    return "UNKNOWN";
}