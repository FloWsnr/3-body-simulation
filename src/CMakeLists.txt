add_library(${LIB_NAME}
            n_body_system.cpp
            simulation.cpp
            read_config.cpp
            com_parser.cpp
            logger.cpp
            data_writer.cpp)
target_include_directories(${LIB_NAME} PUBLIC ../include)
target_compile_features(${LIB_NAME} PUBLIC cxx_std_23)

## Add nlohmann/json
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
target_link_libraries(${LIB_NAME} PUBLIC nlohmann_json::nlohmann_json)