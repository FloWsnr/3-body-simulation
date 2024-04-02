
#pragma once
#include <fstream>
#include <nlohmann/json.hpp>

class ConfigReader
{
public:
    ConfigReader(const std::string &file_path);
    nlohmann::json getData();

private:
    std::fstream file;
    nlohmann::json data;
};