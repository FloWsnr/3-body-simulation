// using namespace std;

#include <string>
#include <array>
#include <iostream>

#include "physics.hpp"


const int NUMBER_MASSES = 3;

class SystemOfMasses
{
    std::array<Mass &, NUMBER_MASSES> masses;

public:
    SystemOfMasses(std::array<Mass &, NUMBER_MASSES> masses)
    {
        this->masses = masses;
    };

private:
    double compute_acceleration(Mass &mass){

    };
};

physics::Mass(std::string name, double mass, std::array<double, 3> position, std::array<double, 3> velocity, std::array<double, 3> acceleration)
{
    this->name = name;
    this->mass = mass;
    this->position = position;
    this->velocity = velocity;
    this->acceleration = acceleration;
};