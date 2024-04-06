#include <gtest/gtest.h>
#include <filesystem>

#include "data_writer.hpp"
#include "body.hpp"
#include "n_body_system.hpp"


TEST(DataWriterTests, TestWriteTimeStep)
{
    std::vector<Body> bodies = { Body{}, Body{}, Body{} };
    NBodySystem test_system = NBodySystem(bodies);

    std::string file_path = std::filesystem::temp_directory_path().string() + "/test_data.csv";
    DataWriter data_writer = DataWriter(file_path);

    data_writer.writeTimeStep(0, test_system);
}