#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

#include "body.hpp"
#include "n_body_system.hpp"

class Logger
{
public:
    Logger(bool verbose = false);
    Logger(const std::string& file, bool verbose = false);

    void logMessage(const std::string& message, int level = 0) const;
    void logBody(const Body& body, int level = 0) const;
    void logNBodySystem(const NBodySystem& n_body_system, int level = 0) const;

    template <typename T>
    void logArray(const T& array) const;
private:
    bool verbose{ false };

    // Pointer to output stream, no ownership since std::cout is not owned
    std::ostream* outputStream;

    // Unique pointer to file stream, ownership since file stream is owned
    std::unique_ptr<std::ofstream> fileStream;
};