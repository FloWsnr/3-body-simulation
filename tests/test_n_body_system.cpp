#include <array>
#include <cmath>
#include <gtest/gtest.h>

#include "body.hpp"
#include "n_body_system.hpp"

TEST(NBodySystemTests, TestConstructor)
{
  std::array<Body, 3> bodies = {Body(), Body(), Body()};
  NBodySystem<3> test_system = NBodySystem<3>(bodies);

  std::array<Body, 3> bodies_out = test_system.getBodies();

  // Test if the bodies are the same (not same object, but same values)
  for (int i = 0; i < 3; i++)
  {
    std::array<double, 3> pos = bodies[i].getPosition();
    std::array<double, 3> pos_out = bodies_out[i].getPosition();

    for (int j = 0; j < 3; j++)
    {
      ASSERT_EQ(pos[j], pos_out[j]);
    }
  }
}

TEST(NBodySystemTests, TestCalcDistance)
{
  Body body1 = Body();
  Body body2 = Body();

  std::array<Body, 2> bodies = {body1, body2};

  NBodySystem<2> test_system = NBodySystem<2>(bodies);

  double distance = test_system.calcDistance(body1, body2);

  ASSERT_EQ(distance, 0);
}