#include <gtest/gtest.h>
#include "mass.hpp"

TEST(MassTests, ConstructorTest)
{
  std::string _name = "Test";
  double _mass = 1.0;
  std::array<double, 3> _position = {0.0, 0.0, 0.0};
  std::array<double, 3> _velocity = {0.0, 0.0, 0.0};
  std::array<double, 3> _acceleration = {0.0, 0.0, 0.0};

  Mass test_mass = Mass(_name, _mass, _position, _velocity, _acceleration);

  auto mass_pos = test_mass.getPosition();
  auto mass_vel = test_mass.getVelocity();
  auto mass_acc = test_mass.getAcceleration();

  EXPECT_EQ(mass_pos, _position);
  EXPECT_EQ(mass_vel, _velocity);
  EXPECT_EQ(mass_acc, _acceleration);
};