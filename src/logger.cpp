#include <iostream>
#include <string>

#include "logger.hpp"
#include "body.hpp"
#include "n_body_system.hpp"

Logger::Logger(bool verbose)
    : verbose{ verbose }
{
}

void Logger::logMessage(const std::string& message, int level)
{
    std::string indent{ std::string(level, ' ') };
    std::cout << indent << message << std::endl;
}

void Logger::logBody(const Body& body, int level)
{
    std::string indent{ std::string(level, ' ') };
    std::cout << indent << "Body: " << body.name << std::endl;
    std::cout << indent << "  Mass: " << body.mass << std::endl;
    std::cout << indent << "  Position: ";
    logArray(body.position);
    std::cout << indent << "  Velocity: ";
    logArray(body.velocity);
}


template <typename T>
void Logger::logArray(const T& array)
{
    std::cout << "[";
    for (auto& element : array)
    {
        std::cout << element;

        // Print comma if not last element
        if (&element != &array.back())
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}