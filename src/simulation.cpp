#include <vector>
#include <array>
#include <cmath>
#include <iostream>
#include <chrono>

#include "n_body_system.hpp"
#include "body.hpp"
#include "simulation.hpp"

/****************************************
 * Simulation class implementation
 * **************************************/
Simulation::Simulation(NBodySystem n_body_system, const Logger& main_logger)
    : n_body_system{ n_body_system }, logger{ main_logger }
{
}

const double& Simulation::getTime() const
{
    return current_time;
}

const NBodySystem& Simulation::getNBodySystem() const
{
    return n_body_system;
}

void Simulation::simulate_timestep(double dt)
{
    // Simulate the movement of the bodies
    const std::vector<Body>& bodies = n_body_system.getBodies();

    // iterate over all bodies
    for (int i = 0; i < bodies.size(); i++)
    {
        std::array<double, 3> total_acceleration = { 0, 0, 0 };

        // iterate over all other bodies
        for (int j = 0; j < bodies.size(); j++)
        {
            if (i != j)
            {
                // Calculate the acceleration between the two bodies (i and j)
                std::array<double, 3> acceleration = n_body_system.calcAcceleration(bodies[i], bodies[j]);
                // Add the acceleration to the total acceleration of body i
                for (int k = 0; k < 3; k++)
                {
                    total_acceleration[k] += acceleration[k];
                }
            }
        }

        // Calculate the new velocity of body i
        std::array<double, 3> velocity = n_body_system.getVelocityOfBody(i);
        for (int k = 0; k < 3; k++)
        {
            velocity[k] += total_acceleration[k] * dt;
        }
        n_body_system.setVelocityOfBody(i, velocity);
    }

    // Update the position of the bodies
    for (int i = 0; i < bodies.size(); i++)
    {
        std::array<double, 3> position = n_body_system.getPositionOfBody(i);
        std::array<double, 3> velocity = n_body_system.getVelocityOfBody(i);
        for (int k = 0; k < 3; k++)
        {
            position[k] += velocity[k] * dt;
        }
        n_body_system.setPositionOfBody(i, position);
    }
}

void Simulation::simulate(double dt, double end_time, double logEvery)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    while (current_time <= end_time)
    {
        simulate_timestep(dt);
        if (std::fmod(current_time, logEvery) == 0)
        {
            logger.logMessage("Time: " + std::to_string(current_time), 0);
            logger.logNBodySystem(n_body_system, 1);
        }
        current_time += dt;
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::string time = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count());
    logger.logMessage("Simulation took: " + time + "ms", 0);
}