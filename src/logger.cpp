#include <iostream>
#include <string>

#include "logger.hpp"
#include "body.hpp"
#include "n_body_system.hpp"

Logger::Logger(bool verbose)
    : verbose{ verbose }
{
}

Logger::Logger(std::string file, bool verbose)
    : verbose{ verbose }
{
    output_stream.open(file);
    if (!output_stream.is_open())
    {
        std::cerr << "Failed to open file: " << file << std::endl;
    }
}


void Logger::logMessage(const std::string& message, int level)
{
    std::string indent{ std::string(level, ' ') };
    this->output_stream << indent << message << "\n";
}

void Logger::logBody(const Body& body, int level)
{
    std::string indent{ std::string(level, ' ') };
    this->output_stream << indent << "Body: " << body.name << "\n";
    this->output_stream << indent << "  Mass: " << body.mass << "\n";
    this->output_stream << indent << "  Position: ";
    logArray(body.position);
    this->output_stream << indent << "  Velocity: ";
    logArray(body.velocity);
}


template <typename T>
void Logger::logArray(const T& array)
{
    this->output_stream << "[";
    for (auto& element : array)
    {
        this->output_stream << element;

        // Print comma if not last element
        if (&element != &array.back())
        {
            this->output_stream << ", ";
        }
    }
    this->output_stream << "]" << "\n";
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