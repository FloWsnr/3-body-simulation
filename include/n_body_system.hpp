#pragma once // Include guard to only include the file once

#include <array>
#include <vector>
#include "body.hpp"

/*******************************************************
 *******************************************************
 * NBodySystem class
 *******************************************************
 ******************************************************/

 /****************************************
  * NBodySystem class declaration
  * **************************************/

class NBodySystem
{
public:
    NBodySystem(std::vector<Body> bodies);

    const std::vector<Body>& getBodies();
    void setBodies(const std::vector<Body>& bodies);

    const std::array<double, 3>& getPositionOfBody(int i);
    const std::array<double, 3>& getVelocityOfBody(int i);

    void setPositionOfBody(int i, const std::array<double, 3>& position);
    void setVelocityOfBody(int i, const std::array<double, 3>& velocity);

    std::array<double, 3> calcDistanceVector(const Body& body1, const Body& body2);
    double calcDistanceMagnitude(const std::array<double, 3>& distance_vector);
    std::array<double, 3> calcAcceleration(const Body& body1, const Body& body2);

private:
    std::vector<Body> bodies;
};