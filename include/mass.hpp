#include <array>
#include <string>

#ifndef PHYSICS_HPP
#define PHYSICS_HPP

class Mass
{
public:
    Mass();

    Mass(std::string name, double mass, std::array<double, 3> position, std::array<double, 3> velocity, std::array<double, 3> acceleration);

    // Getter and setter for pos, vel, and acc
    std::array<double, 3> getPosition();
    void setPosition(std::array<double, 3> position);

    std::array<double, 3> getVelocity();
    void setVelocity(std::array<double, 3> velocity);

    std::array<double, 3> getAcceleration();
    void setAcceleration(std::array<double, 3> acceleration);

    // Getter and setter for name and mass
    std::string getName();
    void setName(std::string name);

    double getMass();
    void setMass(double mass);

private:
    std::string name;
    double mass;
    std::array<double, 3> position;
    std::array<double, 3> velocity;
    std::array<double, 3> acceleration;
};

#endif