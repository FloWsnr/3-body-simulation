#include <iostream>
#include <vector>

#include "read_config.hpp"
#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"
#include "com_parser.hpp"
#include "logger.hpp"

int main(int argc, char* argv[])
{
    // Parse command line arguments
    ComParser com_parser(argc, argv);
    Arguments arguments = com_parser.parse();

    // Read config file
    ConfigReader config(arguments.config_path);

    // Create logger
    const std::string log_file = config.getLogFile();
    Logger logger = Logger(log_file, arguments.verbose);

    std::vector<Body> bodies = config.getBodies();
    NBodySystem n_body_system(bodies);
    logger.logNBodySystem(n_body_system, 1);

    logger.logMessage("Starting N body simulation", 0);
    logger.logMessage("--------------------------", 0);

    Simulation sim(n_body_system, logger);

    double duration = config.getDuration();
    double timestep = config.getTimestep();

    logger.logMessage("Start simulation:", 0);
    sim.simulate(timestep, duration);

    logger.logMessage("Simulation complete", 0);
    return 0;
};