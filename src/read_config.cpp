#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

#include "read_config.hpp"
ConfigReader::ConfigReader(const std::string& file_path)
{
    std::ifstream file(file_path);
    this->data = nlohmann::json::parse(file);
}

Configuration ConfigReader::loadConfiguration()
{
    Configuration config;
    config.log_file = this->getLogFile();
    config.log_every = this->getLogEvery();
    config.timestep = this->getTimestep();
    config.duration = this->getDuration();
    config.data_file = this->getDataFile();
    config.write_every = this->getWriteEvery();
    config.bodies = this->getBodies();
    return config;
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

int ConfigReader::getLogEvery()
{
    return this->data.at("Logging").at("LogEvery");
}


std::string ConfigReader::getLogFile()
{
    return this->data.at("Logging").at("LogFile");
}

double ConfigReader::getTimestep()
{
    return this->data.at("Simulation").at("Timestep");
}

double ConfigReader::getDuration()
{
    return this->data.at("Simulation").at("Duration");
}

std::string ConfigReader::getDataFile()
{
    return this->data.at("Simulation").at("DataFile");
}

int ConfigReader::getWriteEvery()
{
    return this->data.at("Simulation").at("WriteEvery");
}