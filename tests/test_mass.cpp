#include <array>
#include <gtest/gtest.h>
#include "mass.hpp"

TEST(MassTests, TestConstructor)
{
  std::string _name = "Test";
  double _mass = 1.0;
  std::array<double, 3> _position = {0.0, 0.0, 0.0};
  std::array<double, 3> _velocity = {0.0, 0.0, 0.0};
  std::array<double, 3> _acceleration = {3.0, 3.0, 3.0};

  Mass test_mass = Mass(_name, _mass, _position, _velocity, _acceleration);

  std::array<double, 3> mass_acc = test_mass.getAcceleration();

  for (int i = 0; i < 3; i++)
  {
    EXPECT_EQ(mass_acc[i], _acceleration[i]);
  }
};

TEST(MassTests, GetterTest)
{
  std::string _name = "Test";
  double _mass = 1.0;
  std::array<double, 3> _position = {0.0, 0.0, 0.0};
  std::array<double, 3> _velocity = {0.0, 0.0, 0.0};
  std::array<double, 3> _acceleration = {0.0, 0.0, 0.0};

  Mass test_mass = Mass(_name, _mass, _position, _velocity, _acceleration);

  std::array<double, 3> mass_pos = test_mass.getPosition();
  std::array<double, 3> mass_vel = test_mass.getVelocity();
  std::array<double, 3> mass_acc = test_mass.getAcceleration();

  EXPECT_EQ(mass_pos, _position);
  EXPECT_EQ(mass_vel, _velocity);
  EXPECT_EQ(mass_acc, _acceleration);
};

TEST(MassTests, SetterTest)
{
  std::string _name = "Test";
  double _mass = 1.0;
  std::array<double, 3> _position = {0.0, 0.0, 0.0};
  std::array<double, 3> _velocity = {0.0, 0.0, 0.0};
  std::array<double, 3> _acceleration = {0.0, 0.0, 0.0};

  Mass test_mass = Mass(_name, _mass, _position, _velocity, _acceleration);

  std::array<double, 3> new_pos = {1.0, 1.0, 1.0};
  std::array<double, 3> new_vel = {1.0, 1.0, 1.0};
  std::array<double, 3> new_acc = {1.0, 1.0, 1.0};

  test_mass.setPosition(new_pos);
};
