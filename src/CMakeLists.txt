add_library(${LIB_NAME} lib.cpp)
target_include_directories(n_body_system PUBLIC ../include)
target_compile_features(n_body_system PUBLIC cxx_std_23)