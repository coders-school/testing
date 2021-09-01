cmake_minimum_required(VERSION 3.10)
project(sortingTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} catch_amalgamated.cpp catch_main.cpp test.cpp)
# target_compile_features(${PROJECT_NAME} PRIVATE std_cxx_version)
