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

    const std::array<Body, N> &getBodies();
    void setBodies(std::array<Body, N> bodies);

    const std::array<double, 3> &getPositionOfBody(int i);
    const std::array<double, 3> &getVelocityOfBody(int i);

    void setPositionOfBody(int i, const std::array<double, 3> &position);
    void setVelocityOfBody(int i, const std::array<double, 3> &velocity);

    std::array<double, 3> calcDistanceVector(const Body &body1, const Body &body2);
    double calcDistanceMagnitude(const std::array<double, 3> &distance_vector);
    std::array<double, 3> calcAcceleration(const Body &body1, const Body &body2);

private:
    std::array<Body, N> bodies;
};

/****************************************
 *
 * NBodySystem class implementation
 *
 * **************************************/

template <std::size_t N>
NBodySystem<N>::NBodySystem(std::array<Body, N> bodies)
    : bodies(bodies)
{
}

/****************************************
 * Getters and setters
 * **************************************/

template <std::size_t N>
void NBodySystem<N>::setBodies(std::array<Body, N> bodies)
{
    this->bodies = bodies;
}

template <std::size_t N>
const std::array<Body, N> &NBodySystem<N>::getBodies()
{
    return bodies;
}

template <std::size_t N>
const std::array<double, 3> &NBodySystem<N>::getPositionOfBody(int i)
{
    return bodies[i].position;
}

template <std::size_t N>
const std::array<double, 3> &NBodySystem<N>::getVelocityOfBody(int i)
{
    return bodies[i].velocity;
}

template <std::size_t N>
void NBodySystem<N>::setPositionOfBody(int i, const std::array<double, 3> &position)
{
    bodies[i].position = position;
}

template <std::size_t N>
void NBodySystem<N>::setVelocityOfBody(int i, const std::array<double, 3> &velocity)
{
    bodies[i].velocity = velocity;
}

/****************************************
 * Physics
 * **************************************/

template <std::size_t N>
std::array<double, 3> NBodySystem<N>::calcDistanceVector(const Body &body1, const Body &body2)
{
    std::array<double, 3> distance_vector;

    for (int i = 0; i < 3; i++)
    {
        distance_vector[i] = body1.position[i] - body2.position[i];
    }
    return distance_vector;
}

template <std::size_t N>
double NBodySystem<N>::calcDistanceMagnitude(const std::array<double, 3> &distance_vector)
{
    double distance_magnitude = 0.0;
    for (int i = 0; i < 3; i++)
    {
        distance_magnitude += distance_vector[i] * distance_vector[i];
    }
    return std::sqrt(distance_magnitude);
}

template <std::size_t N>
std::array<double, 3> NBodySystem<N>::calcAcceleration(const Body &body1, const Body &body2)
{
    std::array<double, 3> acceleration;

    // Calculate the gravitational force between two masses
    constexpr double G = 6.67430e-11; // Gravitational constant
    const double &mass1 = body1.mass;
    const double &mass2 = body2.mass;

    std::array<double, 3> distance_vector = calcDistanceVector(body1, body2);
    double distance_magnitude = calcDistanceMagnitude(distance_vector);

    double acc = G * mass2 / std::pow(distance_magnitude, 3);
    for (int i = 0; i < 3; i++)
    {
        acceleration[i] = acc * distance_vector[i];
    }

    return acceleration;
}