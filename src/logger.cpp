#include <iostream>
#include <string>

#include "logger.hpp"
#include "body.hpp"
#include "n_body_system.hpp"

Logger::Logger(bool verbose)
    : verbose{ verbose }
{
    // pointer points at std::cout
    outputStream = &std::cout;
}

Logger::Logger(const std::string& file, bool verbose)
    : verbose{ verbose }
{

    fileStream = std::make_unique<std::ofstream>(file);

    // pointer points at file stream
    outputStream = fileStream.get();
}

void Logger::logMessage(const std::string& message, int level)
{
    std::string indent{ std::string(level, ' ') };
    *outputStream << indent << message << "\n";
}

void Logger::logBody(const Body& body, int level)
{
    std::string indent{ std::string(level, ' ') };


    *outputStream << indent << "Body: " << body.name << "\n";
    *outputStream << indent << "  Mass: " << body.mass << "\n";
    *outputStream << indent << "  Position: ";
    logArray(body.position);
    *outputStream << indent << "  Velocity: ";
    logArray(body.velocity);
}


template <typename T>
void Logger::logArray(const T& array)
{
    *outputStream << "[";
    for (auto& element : array)
    {
        *outputStream << element;

        // Print comma if not last element
        if (&element != &array.back())
        {
            *outputStream << ", ";
        }
    }
    *outputStream << "]" << "\n";
}


void Logger::logNBodySystem(const NBodySystem& n_body_system, int level)
{
    std::string indent{ std::string(level, ' ') };
    const std::vector<Body>& bodies = n_body_system.getBodies();
    for (const auto& body : bodies)
    {
        logBody(body, level + 1);
    }
}