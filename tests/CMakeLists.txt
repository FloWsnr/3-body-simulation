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
)

target_link_libraries(
    tests PRIVATE # Private because we don't want to expose the test library to the users of our library
    ${LIB_NAME}
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(tests)