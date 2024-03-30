// using namespace std;

#include <string>
#include <array>
#include <iostream>

#include "../include/mass.hpp"

const int NUMBER_MASSES = 3;

/*********************************************************
Constructor with all params for Mass
*********************************************************/
Mass::Mass(std::string name, double mass, std::array<double, 3> position, std::array<double, 3> velocity, std::array<double, 3> acceleration)
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
std::array<double, 3> Mass::getPosition()
{
    return this->position;
};

void Mass::setPosition(std::array<double, 3> position)
{
    this->position = position;
};

std::array<double, 3> Mass::getVelocity()
{
    return this->velocity;
};

void Mass::setVelocity(std::array<double, 3> velocity)
{
    this->velocity = velocity;
};

std::array<double, 3> Mass::getAcceleration()
{
    return this->acceleration;
};

void Mass::setAcceleration(std::array<double, 3> acceleration)
{
    this->acceleration = acceleration;
};

/*********************************************************
 * Getter and setter for name and mass
 * *******************************************************/

std::string Mass::getName()
{
    return this->name;
};

void Mass::setName(std::string name)
{
    this->name = name;
};

double Mass::getMass()
{
    return this->mass;
};

void Mass::setMass(double mass)
{
    this->mass = mass;
};