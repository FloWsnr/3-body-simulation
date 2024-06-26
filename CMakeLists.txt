cmake_minimum_required(VERSION 3.22)
if(${CMAKE_VERSION} VERSION_LESS 3.22)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(3_body_problem VERSION 0.1.0
        DESCRIPTION "A simple 3 body problem simulation"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# define lib name as variable
set(LIB_NAME n_body_system) # must be defined before the lower cmake files are run

# compile the library
add_subdirectory(src)

# compile the application
add_subdirectory(apps)

enable_testing()
# compile the tests
add_subdirectory(tests)
