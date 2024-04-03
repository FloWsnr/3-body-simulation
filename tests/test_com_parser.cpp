#include <gtest/gtest.h>
#include <iostream>

#include "com_parser.hpp"

TEST(ComParser, TestParse)
{
    char* args[] = { (char*)"./test_app", (char*)"-c", (char*)"config.json" };

    ComParser com_parser(3, args);
    Arguments arguments = com_parser.parse();

    EXPECT_FALSE(arguments.help);
    EXPECT_FALSE(arguments.verbose);

    EXPECT_EQ(arguments.config_path, "config.json");
}
