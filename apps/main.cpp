#include <iostream>
#include <vector>

#include "read_config.hpp"
#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"
#include "com_parser.hpp"

int main(int argc, char* argv[])
{
    std::cout << "3-body simulation" << std::endl;
    std::cout << "-----------------" << std::endl;

    ComParser com_parser(argc, argv);
    Arguments arguments = com_parser.parse();


    ConfigReader config(arguments.config_path);
    std::vector<Body> bodies = config.getBodies();
    double duration = config.getDuration();
    double timestep = config.getTimestep();

    std::cout << "Start simulation:" << std::endl;
    std::cout << "  Duration: " << duration << std::endl;
    std::cout << "  Timestep: " << timestep << std::endl;

    NBodySystem n_body_system(bodies);
    Simulation sim(bodies);


    sim.simulate(duration, timestep);

    std::cout << "Simulation done!" << std::endl;
    return 0;
};