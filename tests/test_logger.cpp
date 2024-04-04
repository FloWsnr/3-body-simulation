#include <gtest/gtest.h>
#include <filesystem>

#include "logger.hpp"


TEST(LoggerTests, TestLogMessageToConsole)
{
    Logger logger = Logger(false);
    logger.logMessage("Test message", 0);
}

TEST(LoggerTests, TestLogMessageToFile)
{
    std::string file_path = std::filesystem::temp_directory_path().string() + "/test_log.txt";
    Logger logger = Logger(file_path, false);
    logger.logMessage("Test message", 0);
}