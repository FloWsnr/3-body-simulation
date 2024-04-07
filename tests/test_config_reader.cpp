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

TEST(ConfigReaderTests, TestGetConfig)
{
    // This is bad practice, since the directory is hardcoded
    // TODO: Make cmake variable for the test directory
    std::string file_path = "/home/flwi/Coding/3-body-simulation/tests/test_config.json";
    ConfigReader reader(file_path);

    Configuration config = reader.loadConfiguration();
    EXPECT_EQ(config.bodies.at(0).name, "Mercury");
    EXPECT_EQ(config.bodies.at(0).mass, 3.301e23);

}