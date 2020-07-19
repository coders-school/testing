cmake_minimum_required(VERSION 3.10)

project(bowling)

set(CMAKE_CXX_STANDARD 17)

set(TEST_FILES tests.cpp)

add_library(lib STATIC ${TEST_FILES})
add_executable(${PROJECT_NAME}-ut catchMain.cpp)

target_link_libraries(${PROJECT_NAME}-ut lib)

enable_testing()
add_test(NAME bowlingTests COMMAND ${PROJECT_NAME}-ut)
