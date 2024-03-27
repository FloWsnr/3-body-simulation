cmake_minimum_required(VERSION 3.0.0)
project(3_body_problem VERSION 0.1.0 LANGUAGES C CXX)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
add_executable(
    3_body_problem
    src/main.cpp
    )


#######################################################
# Add the GoogleTest library ##########################
#######################################################

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
    test_main
    tests/test_main.cpp
)
# add_test(
#     NAME test_main
#     COMMAND test_main)

target_link_libraries(
    test_main
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(test_main)
