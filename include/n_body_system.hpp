#pragma once // Include guard to only include the file once

#include <array>
#include "mass.hpp"

template <std::size_t N>
class NBodySystem
{
public:
    NBodySystem();
    NBodySystem(std::array<Mass, N> masses);

    std::array<Mass, N> getMasses();

private:
    std::array<Mass, N> masses;
};

// Simulation class inherits from NBodySystem
template <std::size_t N>
class Simulation
{
public:
    Simulation();
    Simulation(NBodySystem<N> n_body_system);

    void simulate();

private:
    NBodySystem<N> n_body_system;
};