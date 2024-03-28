// using namespace std;

#include <string>
#include <array>
#include <iostream>

const double G = 6.67430e-11;
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

class Mass
{
    std::string name;
    double mass;
    std::array<double, 3> position;
    std::array<double, 3> velocity;
    std::array<double, 3> acceleration;

public:
    Mass(std::string name, double mass, std::array<double, 3> position, std::array<double, 3> velocity, std::array<double, 3> acceleration)
    {
        this->name = name;
        this->mass = mass;
        this->position = position;
        this->velocity = velocity;
        this->acceleration = acceleration;
    }

    void updatePosition(double dt)
    {
        for (int i = 0; i < 3; i++)
        {
            position[i] += velocity[i] * dt + 0.5 * acceleration[i] * dt * dt;
        }
    }

    void updateVelocity(double dt)
    {
        for (int i = 0; i < 3; i++)
        {
            velocity[i] += acceleration[i] * dt;
        }
    }

    void updateAcceleration(std::array<double, 3> newAcceleration)
    {
        acceleration = newAcceleration;
    }
};