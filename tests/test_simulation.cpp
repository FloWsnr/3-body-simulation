#include <array>
#include <cmath>
#include <filesystem>
#include <gtest/gtest.h>

#include "body.hpp"
#include "n_body_system.hpp"
#include "simulation.hpp"
#include "logger.hpp"
#include "data_writer.hpp"

TEST(SimulationTests, TestSimulateTimestep)
{
  std::vector<Body> bodies = { Body{"Body1", 1, {0, 0, 0}, {0, 0, 0}},
                                Body{"Body2", 1, {1, 1, 1}, {1, 1, 1}},
                                Body{"Body3", 1, {2, 2, 2}, {2, 2, 2}} };
  NBodySystem n_body_system = NBodySystem(bodies);
  Logger logger = Logger();

  std::string data_path = std::filesystem::temp_directory_path().string() + "/test_sim_log.txt";
  DataWriter data_writer = DataWriter(data_path);

  Simulation test_simulation = Simulation(n_body_system, data_writer, logger);

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
  Logger logger = Logger();

  std::string data_path = std::filesystem::temp_directory_path().string() + "/test_sim_log.txt";
  DataWriter data_writer = DataWriter(data_path);

  Simulation test_simulation = Simulation(n_body_system, data_writer, logger);

  test_simulation.simulate(1.0, 100.0);

  std::array<double, 3> body1_pos = test_simulation.getNBodySystem().getPositionOfBody(0);

  EXPECT_NE(body1_pos[0], bodies[0].position[0]);
  EXPECT_NE(body1_pos[1], bodies[0].position[1]);
  EXPECT_NE(body1_pos[2], bodies[0].position[2]);
}

TEST(SimulationTests, TestSimulateWithFileLogging)
{
  std::vector<Body> bodies = { Body{"Body1", 1, {0, 0, 0}, {0, 0, 0}},
                                Body{"Body2", 1, {1, 1, 1}, {1, 1, 1}},
                                Body{"Body3", 1, {2, 2, 2}, {2, 2, 2}} };
  NBodySystem n_body_system = NBodySystem(bodies);

  std::string log_path = std::filesystem::temp_directory_path().string() + "/test_sim_log.txt";
  Logger logger = Logger(log_path);

  std::string data_path = std::filesystem::temp_directory_path().string() + "/test_sim_data.csv";
  DataWriter data_writer = DataWriter(data_path);


  Simulation test_simulation = Simulation(n_body_system, data_writer, logger);

  test_simulation.simulate(1.0, 100.0);

  std::array<double, 3> body1_pos = test_simulation.getNBodySystem().getPositionOfBody(0);

  EXPECT_NE(body1_pos[0], bodies[0].position[0]);
  EXPECT_NE(body1_pos[1], bodies[0].position[1]);
  EXPECT_NE(body1_pos[2], bodies[0].position[2]);
}