#pragma once
#include <string>
#include <vector>

struct Arguments {
    bool help{ false };
    bool verbose{ false };
    std::string config_path;
};


class ComParser {
public:
    ComParser(int num_args, char* args[]);
    Arguments parse();

private:
    std::vector<std::string> args;
    Arguments arguments;

    void printHelp();
    void printConfigMissing();
    void parseConfigPath();

};