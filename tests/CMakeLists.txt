#######################################################
# Add the GoogleTest library ##########################
#######################################################

# GoogleTest requires at least C++14
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


#######################################################
# Add the tests #######################################
#######################################################

add_executable(
    tests
    test_n_body_system.cpp
    test_body.cpp
    test_simulation.cpp
    test_config_reader.cpp
    test_com_parser.cpp
    test_logger.cpp
    test_data_writer.cpp
)

target_link_libraries(
    tests PRIVATE # Private because we don't want to expose the test library to the users of our library
    GTest::gtest_main
    ${LIB_NAME}
)
target_include_directories(tests PUBLIC ../include)

include(GoogleTest)
gtest_discover_tests(tests)