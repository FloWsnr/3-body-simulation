add_library(mass mass.cpp)
target_include_directories(mass PUBLIC ../include)
# require at least c++11
target_compile_features(mass PUBLIC cxx_std_20)