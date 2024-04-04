
#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

#include "body.hpp"

class ConfigReader
{
public:
    ConfigReader(const std::string& file_path);
    const nlohmann::json& getData();
    // Setter not needed, since the data is read-only

    std::vector<Body> getBodies();
    std::string getLogFile();
    double getTimestep();
    double getDuration();

private:
    std::fstream file;
    nlohmann::json data;
};