#include <array>
#include <cmath>
#include <gtest/gtest.h>

#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"

TEST(SimulationTests, TestConstructor)
{
  std::array<Body, 3> bodies = {Body{}, Body{}, Body{}};
  NBodySystem<3> n_body_system = NBodySystem<3>(bodies);
  Simulation<3> test_simulation = Simulation<3>(n_body_system, 1.0);

  EXPECT_EQ(test_simulation.getTime(), 1.0);
}

TEST(SimulationTests, TestSimulateTimestep)
{
  std::array<Body, 3> bodies = {Body{"Body1", 1, {0, 0, 0}, {0, 0, 0}},
                                Body{"Body2", 1, {1, 1, 1}, {1, 1, 1}},
                                Body{"Body3", 1, {2, 2, 2}, {2, 2, 2}}};
  NBodySystem<3> n_body_system = NBodySystem<3>(bodies);
  Simulation<3> test_simulation = Simulation<3>(n_body_system, 0.0);

  test_simulation.simulate_timestep(1.0);
}

TEST(SimulationTests, TestSimulate)
{
  std::array<Body, 3> bodies = {Body{"Body1", 1, {0, 0, 0}, {0, 0, 0}},
                                Body{"Body2", 1, {1, 1, 1}, {1, 1, 1}},
                                Body{"Body3", 1, {2, 2, 2}, {2, 2, 2}}};
  NBodySystem<3> n_body_system = NBodySystem<3>(bodies);
  Simulation<3> test_simulation = Simulation<3>(n_body_system, 0.0);

  test_simulation.simulate(1.0, 10.0);
}