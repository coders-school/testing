cmake_minimum_required(VERSION 3.10)
project(tests_sort)

find_package(Catch2 3 REQUIRED)
add_executable(${PROJECT_NAME} test_sort.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

