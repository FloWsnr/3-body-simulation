#include <vector>
#include <cmath>
#include "n_body_system.hpp"

/****************************************
 *
 * NBodySystem class implementation
 *
 * **************************************/
NBodySystem::NBodySystem(std::vector<Body> bodies)
    : bodies(bodies)
{
}

/****************************************
 * Getters and setters
 * **************************************/

void NBodySystem::setBodies(const std::vector<Body>& bodies)
{
    this->bodies = bodies;
}

const std::vector<Body>& NBodySystem::getBodies() const
{
    return bodies;
}

const std::array<double, 3>& NBodySystem::getPositionOfBody(int i) const
{
    return bodies[i].position;
}

const std::array<double, 3>& NBodySystem::getVelocityOfBody(int i) const
{
    return bodies[i].velocity;
}

void NBodySystem::setPositionOfBody(int i, const std::array<double, 3>& position)
{
    bodies[i].position = position;
}

void NBodySystem::setVelocityOfBody(int i, const std::array<double, 3>& velocity)
{
    bodies[i].velocity = velocity;
}

/****************************************
 * Physics
 * **************************************/

std::array<double, 3> NBodySystem::calcDistanceVector(const Body& body1, const Body& body2)
{
    std::array<double, 3> distance_vector;

    for (int i = 0; i < 3; i++)
    {
        distance_vector[i] = body1.position[i] - body2.position[i];
    }
    return distance_vector;
}

double NBodySystem::calcDistanceMagnitude(const std::array<double, 3>& distance_vector)
{
    double distance_magnitude = 0.0;
    for (int i = 0; i < 3; i++)
    {
        distance_magnitude += distance_vector[i] * distance_vector[i];
    }
    return std::sqrt(distance_magnitude);
}

std::array<double, 3> NBodySystem::calcAcceleration(const Body& body1, const Body& body2)
{
    std::array<double, 3> acceleration;

    // Calculate the gravitational force between two masses
    constexpr double G = 6.67430e-11; // Gravitational constant
    // const double& mass1 = body1.mass;
    const double& mass2 = body2.mass;

    std::array<double, 3> distance_vector = calcDistanceVector(body1, body2);
    double distance_magnitude = calcDistanceMagnitude(distance_vector);

    double acc = G * mass2 / std::pow(distance_magnitude, 3);
    for (int i = 0; i < 3; i++)
    {
        acceleration[i] = acc * distance_vector[i];
    }

    return acceleration;
}