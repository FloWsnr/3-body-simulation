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

template <std::size_t N>
class Simulation
{
public:
    Simulation(NBodySystem<N> n_body_system, double time = 0.0);

    void simulate_timestep(double dt);
    void simulate(double dt, double end_time);

    double getTime();

private:
    NBodySystem<N> n_body_system;
    double time = 0.0;
};

/****************************************
 * Simulation class implementation
 * **************************************/

template <std::size_t N>
Simulation<N>::Simulation(NBodySystem<N> n_body_system, double time)
    : n_body_system(n_body_system), time(time)
{
}

template <std::size_t N>
double Simulation<N>::getTime()
{
    return time;
}

template <std::size_t N>
void Simulation<N>::simulate_timestep(double dt)
{
    // Simulate the movement of the bodies
    std::array<Body, N> bodies = n_body_system.getBodies();

    // iterate over all bodies
    for (int i = 0; i < N; i++)
    {
        std::array<double, 3> total_velocity = {0, 0, 0};
        std::array<double, 3> total_acceleration = {0, 0, 0};

        // iterate over all other bodies
        for (int j = 0; j < N; j++)
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
        std::array<double, 3> velocity = bodies[i].velocity;
        for (int k = 0; k < 3; k++)
        {
            velocity[k] += total_acceleration[k] * dt;
        }
        bodies[i].velocity = velocity;
    }

    // Update the position of the bodies
    for (int i = 0; i < N; i++)
    {
        std::array<double, 3> position = bodies[i].position;
        std::array<double, 3> velocity = bodies[i].velocity;
        for (int k = 0; k < 3; k++)
        {
            position[k] += velocity[k] * dt;
        }
        bodies[i].position = position;
    }
}

template <std::size_t N>
void Simulation<N>::simulate(double dt, double end_time)
{
    while (time < end_time)
    {
        simulate_timestep(dt);
        time += dt;
    }
}