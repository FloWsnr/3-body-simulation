#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

#include "read_config.hpp"
ConfigReader::ConfigReader(const std::string& file_path)
{
    std::ifstream file(file_path);
    this->data = nlohmann::json::parse(file);
}

const nlohmann::json& ConfigReader::getData()
{
    return this->data;
}

std::vector<Body> ConfigReader::getBodies()
{
    std::vector<Body> bodies;

    for (const auto& body : this->data.at("Bodies"))
    {
        Body new_body(body.at("Name"), body.at("Mass"), body.at("Pos"), body.at("Vel"));
        bodies.push_back(new_body);
    }
    return bodies;
}

double ConfigReader::getLogEvery()
{
    return this->data.at("Logging").at("LogEvery");
}


std::string ConfigReader::getLogFile()
{
    return this->data.at("Logging").at("File");
}

double ConfigReader::getTimestep()
{
    return this->data.at("Simulation").at("Timestep");
}

double ConfigReader::getDuration()
{
    return this->data.at("Simulation").at("Duration");
}