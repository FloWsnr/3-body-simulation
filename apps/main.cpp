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
    const double logEvery = config.getLogEvery();
    Logger logger = Logger(log_file, arguments.verbose);

    std::vector<Body> bodies = config.getBodies();
    NBodySystem n_body_system(bodies);

    logger.logMessage("Initial configuration", 0);
    logger.logMessage("--------------------------", 0);
    logger.logNBodySystem(n_body_system, 1);

    logger.logMessage("--------------------------", 0);
    logger.logMessage("Starting N body simulation", 0);
    logger.logMessage("--------------------------", 0);

    // WHY CANT I PASS A REFERENCE TO THE LOGGER HERE? If I do, I the logger gets copied instead of referenced
    Simulation sim(n_body_system, logger);

    double duration = config.getDuration();
    double timestep = config.getTimestep();

    logger.logMessage("Start simulation:", 1);
    sim.simulate(timestep, duration, logEvery);

    logger.logMessage("Simulation complete", 1);
    return 0;
};