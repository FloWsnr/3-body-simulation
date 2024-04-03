#include <iostream>
#include <vector>

#include "read_config.hpp"
#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"

int main()
{
    ConfigReader config("/home/flwi/Coding/3-body-simulation/apps/default_config.json");
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