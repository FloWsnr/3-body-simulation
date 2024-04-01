#include <array>
#include <gtest/gtest.h>
#include "body.hpp"

TEST(BodyTests, TestMemberInitialization)
{
  std::string _name = "Test";
  double _mass = 1.0;
  std::array<double, 3> _position = {0.0, 0.0, 0.0};
  std::array<double, 3> _velocity = {0.0, 0.0, 0.0};

  Body test_body{.name{_name}, .mass{_mass}, .position{_position}, .velocity{_velocity}};

  EXPECT_EQ(test_body.name, _name);
  EXPECT_EQ(test_body.mass, _mass);

  std::array<double, 3> mass_pos = test_body.position;
  std::array<double, 3> mass_vel = test_body.velocity;

  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(mass_pos[i], _position[i]);
    EXPECT_EQ(mass_vel[i], _velocity[i]);
  }
};