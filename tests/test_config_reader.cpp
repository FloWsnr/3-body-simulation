#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "read_config.hpp"

TEST(ConfigReaderTests, TestGetData)
{
    // This is bad practice, since the directory is hardcoded
    // TODO: Make cmake variable for the test directory
    std::string file_path = "/home/flwi/Coding/3-body-simulation/tests/test_config.json";
    ConfigReader reader(file_path);
    nlohmann::json data = reader.getData();
    EXPECT_EQ(data.at("Bodies").at("Body1").at("Name"), "Mercury");
}

TEST(ConfigReaderTests, TestGetBodies)
{
    // This is bad practice, since the directory is hardcoded
    std::string file_path = "/home/flwi/Coding/3-body-simulation/tests/test_config.json";
    ConfigReader reader(file_path);
    std::vector<Body> bodies = reader.getBodies();
    EXPECT_EQ(bodies.size(), 1);
    EXPECT_EQ(bodies[0].name, "Mercury");
}

TEST(ConfigReaderTests, TestGetDuration)
{
    // This is bad practice, since the directory is hardcoded
    std::string file_path = "/home/flwi/Coding/3-body-simulation/tests/test_config.json";
    ConfigReader reader(file_path);
    double duration = reader.getDuration();
    EXPECT_EQ(duration, 1000);
}

TEST(ConfigReaderTests, TestGetTimestep)
{
    // This is bad practice, since the directory is hardcoded
    std::string file_path = "/home/flwi/Coding/3-body-simulation/tests/test_config.json";
    ConfigReader reader(file_path);
    double timestep = reader.getTimestep();
    EXPECT_EQ(timestep, 1);
}

TEST(ConfigReaderTests, TestGetLogFile)
{
    // This is bad practice, since the directory is hardcoded
    std::string file_path = "/home/flwi/Coding/3-body-simulation/tests/test_config.json";
    ConfigReader reader(file_path);
    std::string log_file = reader.getLogFile();
    EXPECT_EQ(log_file, "log.txt");
}