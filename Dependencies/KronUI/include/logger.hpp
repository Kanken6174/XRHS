#pragma once
#include <iostream>
#include <memory>

#define IGNORE_INFO_LOGS

class Logger
{
public:
    enum class Level
    {
        FATAL,
        ERROR,
        WARNING,
        INFO
    };

    static Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }

    void log(Level level, const std::string& message)
    {
        switch(level)
        {
            case Level::FATAL:
                std::cerr << "\033[31m" << "[FATAL] " << message << "\033[0m" << std::endl;
                break;
            case Level::ERROR:
                std::cerr << "\033[31m" << "[ERROR] " << message << "\033[0m" << std::endl;
                break;
            case Level::WARNING:
                std::cerr << "\033[33m" << "[WARNING] " << message << "\033[0m" << std::endl;
                break;
            case Level::INFO:
#ifndef IGNORE_INFO_LOGS
                std::cout << "[INFO] " << message << std::endl;
#endif
                break;
        }
    }

    void error(const std::string& message)
    {
        log(Level::ERROR, message);
    }

    void warn(const std::string& message)
    {
        log(Level::WARNING, message);
    }

    void info(const std::string& message)
    {
        log(Level::INFO, message);
    }

    void fatal(const std::string& message)
    {
        log(Level::FATAL, message);
        exit(1);
    }

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};