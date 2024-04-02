#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include "read_config.hpp"

TEST(ConfigReaderTests, TestGetData)
{
    std::string file_path = "/home/flwi/Coding/3-body-simulation/apps/default_config.json";
    ConfigReader reader(file_path);
    nlohmann::json data = reader.getData();
    // EXPECT_EQ(data["simulation"]["time"]["dt"], 0.01);
    // EXPECT_EQ(data["simulation"]["time"]["t_end"], 10.0);
    // EXPECT_EQ(data["simulation"]["time"]["t_start"], 0.0);
}