#pragma once

#include <array>
#include <cmath>
#include "body.hpp"
#include "n_body_system.hpp"
#include "logger.hpp"

/*******************************************************
 *******************************************************
 * Simulation class
 *******************************************************
 ******************************************************/
class Simulation
{
public:
    Simulation(NBodySystem n_body_system);
    Simulation(NBodySystem n_body_system, const Logger& logger);

    void simulate_timestep(double dt);
    void simulate(double dt, double end_time);

    const double& getTime() const;
    const NBodySystem& getNBodySystem() const;

    const Logger& logger;
private:
    NBodySystem n_body_system;
    double current_time = 0.0;
};