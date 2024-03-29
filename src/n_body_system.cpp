#include <array>
#include "n_body_system.hpp"

template <std::size_t N>
NBodySystem<N>::NBodySystem()
{
}

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

/****************************************
Simulation class
****************************************/

template <std::size_t N>
Simulation<N>::Simulation()
{
}

template <std::size_t N>
Simulation<N>::Simulation(NBodySystem<N> n_body_system)
{
    this->n_body_system = n_body_system;
}

template <std::size_t N>
void Simulation<N>::simulate()
{
    // Simulate the N-body system
}