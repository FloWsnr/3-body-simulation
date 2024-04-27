#pragma once

#include <array>
#include <cmath>
#include "body.hpp"
#include "n_body_system.hpp"
#include "logger.hpp"
#include "data_writer.hpp"

/*******************************************************
 *******************************************************
 * Simulation class
 *******************************************************
 ******************************************************/
class Simulation
{
public:
    Simulation(NBodySystem _n_body_system, DataWriter& _dataWriter, Logger& _logger);

    void simulate_timestep(double dt);
    void simulate(double dt, double end_time, double logEvery = 1.0, double dataEvery = 1.0);

    const double& getTime() const;
    const NBodySystem& getNBodySystem() const;

private:
    NBodySystem n_body_system;
    DataWriter& dataWriter;
    Logger& logger;
    double current_time = 0.0;

    void outputData(const double& current_time, const double& logEvery, const double& dataEvery) const;
};