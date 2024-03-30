// using namespace std;

#include <string>
#include <array>
#include <iostream>

#include "body.hpp"

const int NUMBER_MASSES = 3;

/*********************************************************
Constructor with all params for Body
*********************************************************/
Body::Body(std::string name, double mass, std::array<double, 3> position, std::array<double, 3> velocity, std::array<double, 3> acceleration)
{
    this->name = name;
    this->mass = mass;
    this->position = position;
    this->velocity = velocity;
    this->acceleration = acceleration;
};

/*********************************************************
Getter and setter for position, velocity, and acceleration
*********************************************************/
std::array<double, 3> Body::getPosition()
{
    return this->position;
};

void Body::setPosition(std::array<double, 3> position)
{
    this->position = position;
};

std::array<double, 3> Body::getVelocity()
{
    return this->velocity;
};

void Body::setVelocity(std::array<double, 3> velocity)
{
    this->velocity = velocity;
};

std::array<double, 3> Body::getAcceleration()
{
    return this->acceleration;
};

void Body::setAcceleration(std::array<double, 3> acceleration)
{
    this->acceleration = acceleration;
};

/*********************************************************
 * Getter and setter for name and mass
 * *******************************************************/

std::string Body::getName()
{
    return this->name;
};

void Body::setName(std::string name)
{
    this->name = name;
};

double Body::getMass()
{
    return this->mass;
};

void Body::setMass(double mass)
{
    this->mass = mass;
};