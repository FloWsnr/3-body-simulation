#pragma once

#include <array>
#include <cmath>
#include "body.hpp"
#include "n_body_system.hpp"

/*******************************************************
 *******************************************************
 * Simulation class
 *******************************************************
 ******************************************************/
class Simulation
{
public:
    Simulation(NBodySystem n_body_system);

    void simulate_timestep(double dt);
    void simulate(double dt, double end_time);

    double getTime();

private:
    NBodySystem n_body_system;
    double current_time = 0.0;
};