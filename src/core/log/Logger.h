#pragma once
#include "Log.h"

/**
 * @brief Static logging utility class.
 *
 * Logger provides a simple interface for logging messages
 * with different severity levels. It is designed as a fully
 * static utility and does not require instantiation.
 */
class Logger
{
public:
    /**
     * @brief Initializes the logging system.
     *
     * This function should be called once before using any logging functions.
     * It can be used to configure output destinations, formats, or sinks.
     */
    static void Init();

    /**
     * @brief Logs a message with a specified severity level.
     *
     * @param level Severity level of the log message.
     * @param message Text message to log.
     */
    static void Log(LogLevel level, const std::string& message);

    /**
     * @brief Logs an informational message.
     *
     * @param message Message to log.
     */
    static void Info(const std::string& message);

    /**
     * @brief Logs a warning message.
     *
     * @param message Message to log.
     */
    static void Warning(const std::string& message);

    /**
     * @brief Logs an error message.
     *
     * @param message Message to log.
     */
    static void Error(const std::string& message);

    /**
     * @brief Logs a debug message.
     *
     * Typically used for development and debugging purposes.
     *
     * @param message Message to log.
     */
    static void Debug(const std::string& message);

private:
    static std::string LevelToString(LogLevel level);
};