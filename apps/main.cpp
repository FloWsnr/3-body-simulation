#include <iostream>
#include <vector>

#include "read_config.hpp"
#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"
#include "com_parser.hpp"
#include "logger.hpp"
#include "data_writer.hpp"

int main(int argc, char* argv[])
{
    // Parse command line arguments
    ComParser com_parser(argc, argv);
    Arguments arguments = com_parser.parse();

    // Read config file
    ConfigReader configReader(arguments.config_path);
    Configuration config = configReader.loadConfiguration();

    // Create logger
    Logger logger = Logger();
    // Create DataWriter
    DataWriter data_writer = DataWriter(config.data_file);

    /***************************************************
    Start the actual simulation
    ***************************************************/

    std::vector<Body> bodies = config.bodies;
    NBodySystem n_body_system(bodies);

    if (arguments.verbose)
    {
        logger.logMessage("Initial configuration", 0);
        logger.logMessage("--------------------------", 0);
        logger.logNBodySystem(n_body_system, 1);
    }
    Simulation sim(n_body_system, data_writer, logger);

    logger.logMessage("--------------------------", 0);
    logger.logMessage("Starting N body simulation", 0);
    logger.logMessage("--------------------------", 0);


    logger.logMessage("Start simulation:", 1);
    sim.simulate(config.timestep, config.duration, config.log_every, config.write_every);

    logger.logMessage("--------------------------", 0);
    logger.logMessage("Simulation complete", 0);
    return 0;
};