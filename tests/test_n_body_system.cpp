#include <array>
#include <cmath>
#include <gtest/gtest.h>

#include "mass.hpp"
#include "n_body_system.hpp"

TEST(NBodySystemTests, TestConstructor)
{
  std::array<Mass, 3> masses = {Mass(), Mass(), Mass()};
  NBodySystem<3> test_system = NBodySystem<3>(masses);

  std::array<Mass, 3> masses_out = test_system.getMasses();

  // Test if the masses are the same (not same object, but same values)
  for (int i = 0; i < 3; i++)
  {
    std::array<double, 3> pos = masses[i].getPosition();
    std::array<double, 3> pos_out = masses_out[i].getPosition();

    for (int j = 0; j < 3; j++)
    {
      ASSERT_EQ(pos[j], pos_out[j]);
    }
  }
}

TEST(NBodySystemTests, TestCalcDistance)
{
  Mass mass1 = Mass();
  Mass mass2 = Mass();

  std::array<Mass, 2> masses = {mass1, mass2};

  NBodySystem<2> test_system = NBodySystem<2>(masses);

  double distance = test_system.calcDistance(mass1, mass2);

  ASSERT_EQ(distance, 0);
}