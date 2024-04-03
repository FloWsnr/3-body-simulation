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

    // Create logger
    Logger logger = Logger(arguments.verbose);

    logger.logMessage("Starting N body simulation", 0);
    logger.logMessage("--------------------------", 0);

    ConfigReader config(arguments.config_path);
    std::vector<Body> bodies = config.getBodies();
    NBodySystem n_body_system(bodies);
    Simulation sim(bodies);

    double duration = config.getDuration();
    double timestep = config.getTimestep();

    logger.logMessage("Start simulation:", 0);
    logger.logMessage("  Duration: " + std::to_string(duration), 0);
    logger.logMessage("  Timestep: " + std::to_string(timestep), 0);

    sim.simulate(duration, timestep);

    logger.logMessage("Simulation complete", 0);
    return 0;
};