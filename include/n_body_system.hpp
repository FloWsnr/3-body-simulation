#pragma once // Include guard to only include the file once

#include <array>
#include "body.hpp"

/*******************************************************
 *******************************************************
 * NBodySystem class
 *******************************************************
 ******************************************************/

/****************************************
 * NBodySystem class declaration
 * **************************************/

template <std::size_t N>
class NBodySystem
{
public:
    NBodySystem(std::array<Body, N> bodies);

    std::array<Body, N> getBodies();
    double calcDistance(Body body1, Body body2);

    double calcForce(Body mass1, Body mass2);

private:
    std::array<Body, N> bodies;
};

/****************************************
 * NBodySystem class implementation
 * **************************************/

template <std::size_t N>
NBodySystem<N>::NBodySystem(std::array<Body, N> bodies)
{
    this->bodies = bodies;
}

template <std::size_t N>
std::array<Body, N> NBodySystem<N>::getBodies()
{
    return bodies;
}

template <std::size_t N>
double NBodySystem<N>::calcDistance(Body body1, Body body2)
{
    // Calculate the Euklidean distance between two masses
    std::array<double, 3> pos1 = body1.getPosition();
    std::array<double, 3> pos2 = body2.getPosition();

    double abs_distance = 0.0;

    for (int i = 0; i < 3; i++)
    {
        abs_distance += std::pow(pos2[i] - pos1[i], 2.0);
    }

    abs_distance = std::sqrt(abs_distance);

    return abs_distance;
}

template <std::size_t N>
double NBodySystem<N>::calcForce(Body body1, Body body2)
{
    // Calculate the gravitational force between two masses
    constexpr double G = 6.67430e-11; // Gravitational constant

    double distance = calcDistance(body1, body1);

    double force = G * body1.getMass() * body2.getMass() / std::pow(distance, 2.0);

    return force;
}

/*******************************************************
 *******************************************************
 * Simulation class
 *******************************************************
 ******************************************************/

template <std::size_t N>
class Simulation
{
public:
    Simulation();
    Simulation(NBodySystem<N> n_body_system);

    void simulate();

private:
    NBodySystem<N> n_body_system;
    double time = 0.0;
};