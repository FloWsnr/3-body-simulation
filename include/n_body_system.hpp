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
    std::array<double, 3> calcDistanceVector(Body body1, Body body2);
    double calcDistanceMagnitude(std::array<double, 3> distance_vector);
    double calcAcceleration(Body body1, Body body2);

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
std::array<double, 3> NBodySystem<N>::calcDistanceVector(Body body1, Body body2)
{
    // Calculate the Euklidean distance between two masses
    std::array<double, 3> pos1 = body1.getPosition();
    std::array<double, 3> pos2 = body2.getPosition();

    std::array<double, 3> distance_vector;

    for (int i = 0; i < 3; i++)
    {
        distance_vector[i] = pos1[i] - pos2[i];
    }
    return distance_vector;
}

template <std::size_t N>
double NBodySystem<N>::calcDistanceMagnitude(std::array<double, 3> distance_vector)
{
    double distance_magnitude = 0.0;
    for (int i = 0; i < 3; i++)
    {
        distance_magnitude += distance_vector[i] * distance_vector[i];
    }
    return std::sqrt(distance_magnitude);
}

// template <std::size_t N>
// double NBodySystem<N>::calcAcceleration(Body body1, Body body2)
// {
//     // Calculate the gravitational force between two masses
//     constexpr double G = 6.67430e-11; // Gravitational constant

//     double mass1 = body1.getMass();
//     double mass2 = body2.getMass();
//     std::array<double, 3> distance_vector = calcDistanceVector(body1, body2);

//     return acceleration;
//}

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