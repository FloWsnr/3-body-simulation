#pragma once

#include <array>
#include <string>

class Mass
{
public:
    Mass(std::string name = "Mass",
         double mass = 0.0,
         std::array<double, 3> position = {0.0, 0.0, 0.0},
         std::array<double, 3> velocity = {0.0, 0.0, 0.0},
         std::array<double, 3> acceleration = {0.0, 0.0, 0.0});

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