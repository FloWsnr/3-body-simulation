#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "body.hpp"
#include "n_body_system.hpp"

class Logger
{
public:
    Logger(bool verbose = false);

    void logMessage(const std::string& message, int level = 0);
    void logBody(const Body& body, int level = 0);
    void logNBodySystem(const NBodySystem& n_body_system, int level = 0);

    template <typename T>
    void logArray(const T& array);
private:
    bool verbose{ false };
};