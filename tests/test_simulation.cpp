#include <array>
#include <cmath>
#include <gtest/gtest.h>

#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"

TEST(SimulationTests, TestConstructor)
{
  std::vector<Body> bodies = { Body{}, Body{}, Body{} };
  NBodySystem n_body_system = NBodySystem(bodies);
  Simulation test_simulation = Simulation(n_body_system);

  EXPECT_EQ(test_simulation.getTime(), 0);
}

TEST(SimulationTests, TestSimulateTimestep)
{
  std::vector<Body> bodies = { Body{"Body1", 1, {0, 0, 0}, {0, 0, 0}},
                                Body{"Body2", 1, {1, 1, 1}, {1, 1, 1}},
                                Body{"Body3", 1, {2, 2, 2}, {2, 2, 2}} };
  NBodySystem n_body_system = NBodySystem(bodies);
  Simulation test_simulation = Simulation(n_body_system);

  test_simulation.simulate_timestep(1.0);

  std::array<double, 3> body1_pos = test_simulation.getNBodySystem().getPositionOfBody(0);

  EXPECT_NE(body1_pos[0], bodies[0].position[0]);
  EXPECT_NE(body1_pos[1], bodies[0].position[1]);
  EXPECT_NE(body1_pos[2], bodies[0].position[2]);
}

TEST(SimulationTests, TestSimulate)
{
  std::vector<Body> bodies = { Body{"Body1", 1, {0, 0, 0}, {0, 0, 0}},
                                Body{"Body2", 1, {1, 1, 1}, {1, 1, 1}},
                                Body{"Body3", 1, {2, 2, 2}, {2, 2, 2}} };
  NBodySystem n_body_system = NBodySystem(bodies);
  Simulation test_simulation = Simulation(n_body_system);

  test_simulation.simulate(1.0, 100.0);

  std::array<double, 3> body1_pos = test_simulation.getNBodySystem().getPositionOfBody(0);

  EXPECT_NE(body1_pos[0], bodies[0].position[0]);
  EXPECT_NE(body1_pos[1], bodies[0].position[1]);
  EXPECT_NE(body1_pos[2], bodies[0].position[2]);
}