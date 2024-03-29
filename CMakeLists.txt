cmake_minimum_required(VERSION 3.22)
if(${CMAKE_VERSION} VERSION_LESS 3.22)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(3_body_problem VERSION 0.1.0
        DESCRIPTION "A simple 3 body problem simulation"
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# compile the library
add_subdirectory(src)


# compile the application
add_subdirectory(apps)



enable_testing()
# compile the tests
add_subdirectory(tests)
