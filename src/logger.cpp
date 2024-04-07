#include <iostream>
#include <string>
#include <chrono>

#include "logger.hpp"
#include "body.hpp"
#include "n_body_system.hpp"

Logger::Logger()
{
    // pointer points at std::cout
    outputStream = &std::cout;
}

Logger::Logger(const std::string& file)
{

    fileStream = std::make_unique<std::ofstream>(file);
    // pointer points at file stream
    outputStream = fileStream.get();

    // Create header line in log file
    logHeader();
}

void Logger::logHeader() const
{
    // Get current time
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t now_c = std::chrono::system_clock::to_time_t(now);

    (*outputStream) << "N body simulation - " << ctime(&now_c);
    (*outputStream) << "-------------------------------------" << "\n";
}

void Logger::logMessage(const std::string& message, int level) const
{
    std::string indent{ std::string(level, ' ') };
    (*outputStream) << indent << message << "\n";
}

void Logger::logBody(const Body& body, int level) const
{
    std::string indent{ std::string(level, ' ') };


    (*outputStream) << indent << "Body: " << body.name << "\n";
    (*outputStream) << indent << "  Mass: " << body.mass << "\n";
    (*outputStream) << indent << "  Position: ";
    logArray(body.position);
    (*outputStream) << indent << "  Velocity: ";
    logArray(body.velocity);
}


template <typename T>
void Logger::logArray(const T& array) const
{
    (*outputStream) << "[";
    for (auto& element : array)
    {
        (*outputStream) << element;

        // Print comma if not last element
        if (&element != &array.back())
        {
            (*outputStream) << ", ";
        }
    }
    (*outputStream) << "]" << "\n";
}


void Logger::logNBodySystem(const NBodySystem& n_body_system, int level) const
{
    std::string indent{ std::string(level, ' ') };
    const std::vector<Body>& bodies = n_body_system.getBodies();
    for (const auto& body : bodies)
    {
        logBody(body, level + 1);
    }
}