
#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

#include "body.hpp"


struct Configuration
{
    std::string log_file;
    int log_every;
    double timestep;
    double duration;
    std::string data_file;
    int write_every;
    std::vector<Body> bodies;
};


class ConfigReader
{
public:
    ConfigReader(const std::string& file_path);
    const nlohmann::json& getData();
    Configuration loadConfiguration();

private:
    std::vector<Body> getBodies();
    std::string getLogFile();
    int getLogEvery();
    double getTimestep();
    double getDuration();
    std::string getDataFile();
    int getWriteEvery();

    std::fstream file;
    nlohmann::json data;
};