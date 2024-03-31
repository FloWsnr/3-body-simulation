#include <array>
#include <cmath>
#include <gtest/gtest.h>

#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"

TEST(SimulationTests, TestConstructor)
{
  std::array<Body, 3> bodies = {Body(), Body(), Body()};
  NBodySystem<3> n_body_system = NBodySystem<3>(bodies);
  Simulation<3> test_simulation = Simulation<3>(n_body_system, 1.0);

  ASSERT_EQ(test_simulation.getTime(), 1.0);
}