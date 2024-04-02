#include <fstream>
#include <nlohmann/json.hpp>

#include "read_config.hpp"
ConfigReader::ConfigReader(const std::string &file_path)
{
    std::ifstream file(file_path);
    this->data = nlohmann::json::parse(file);
}

nlohmann::json ConfigReader::getData()
{
    return this->data;
}