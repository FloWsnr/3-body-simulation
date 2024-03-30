#pragma once // Include guard to only include the file once

#include <array>
#include "mass.hpp"

template <std::size_t N>
class NBodySystem
{
public:
    NBodySystem(std::array<Mass, N> masses);

    std::array<Mass, N> getMasses();

    double calcDistance(Mass mass1, Mass mass2);

private:
    std::array<Mass, N> masses;
};

template <std::size_t N>
NBodySystem<N>::NBodySystem(std::array<Mass, N> masses)
{
    this->masses = masses;
}

template <std::size_t N>
std::array<Mass, N> NBodySystem<N>::getMasses()
{
    return masses;
}

template <std::size_t N>
double NBodySystem<N>::calcDistance(Mass mass1, Mass mass2)
{
    // Calculate the Euklidean distance between two masses
    std::array<double, 3> pos1 = mass1.getPosition();
    std::array<double, 3> pos2 = mass2.getPosition();

    double abs_distance = 0.0;

    for (int i = 0; i < 3; i++)
    {
        abs_distance += std::pow(pos2[i] - pos1[i], 2.0);
    }

    abs_distance = std::sqrt(abs_distance);

    return abs_distance;
}


/****************************************
 * Simulation class
 ****************************************/

template <std::size_t N>
class Simulation
{
public:
    Simulation();
    Simulation(NBodySystem<N> n_body_system);

    void simulate();

private:
    NBodySystem<N> n_body_system;
    double time = 0.0;
};