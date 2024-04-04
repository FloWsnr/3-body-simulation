#include <string>
#include <iostream>
#include "com_parser.hpp"

ComParser::ComParser(int num_args, char* args[])
{
    // check if at least 2 arguments are passed
    if (num_args < 2)
    {
        this->printConfigMissing();
    }

    for (int i = 0; i < num_args; ++i)
    {
        this->args.push_back(args[i]);
    }
}

Arguments ComParser::parse()
{
    // Check for help and verbose flags
    for (std::string& arg : this->args)
    {
        if (arg == "-h" || arg == "--help")
        {
            this->arguments.help = true;
        }
        else if (arg == "-v" || arg == "--verbose")
        {
            this->arguments.verbose = true;
        }
    }

    // Check for config file
    this->parseConfigPath();
    return this->arguments;
}

void ComParser::printConfigMissing()
{
    std::cerr << "Error: No config file specified!" << std::endl;
    this->printHelp();

    std::cout << "You ran the following command:" << std::endl;
    for (std::string& arg : this->args)
    {
        std::cout << arg << " ";
    }
    exit(1);
}

void ComParser::printHelp()
{
    std::cout << "Usage: " << this->args[0] << " -c [config_file]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help: Print this help message" << std::endl;
    std::cout << "  -v, --verbose: Print verbose output" << std::endl;
}

void ComParser::parseConfigPath()
{
    for (int i = 0; i < this->args.size(); ++i)
    {
        if (this->args[i] == "-c" || this->args[i] == "--config")
        {
            if (i + 1 < this->args.size())
            {
                this->arguments.config_path = this->args[i + 1];
            }
            else
            {
                this->printConfigMissing();
            }
        }
    }
}