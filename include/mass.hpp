#include <array>
#include <string>

#ifndef PHYSICS_HPP
#define PHYSICS_HPP

const double G = 6.67430e-11;

class Mass
{
public:
    Mass(std::string name, double mass, std::array<double, 3> position, std::array<double, 3> velocity, std::array<double, 3> acceleration);

    // Getter and setter for pos, vel, and acc
    std::array<double, 3> getPosition();
    void setPosition(std::array<double, 3> position);

    std::array<double, 3> getVelocity();
    void setVelocity(std::array<double, 3> velocity);

    std::array<double, 3> getAcceleration();
    void setAcceleration(std::array<double, 3> acceleration);

private:
    std::string name;
    double mass;
    std::array<double, 3> position;
    std::array<double, 3> velocity;
    std::array<double, 3> acceleration;
};

#endif