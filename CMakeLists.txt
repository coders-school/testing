cmake_minimum_required(VERSION 3.10)

project(testBowlingScore)

set(SRC test.cpp catch.cpp)
set(FLAGS -Wall -Wextra -Werror -pedantic)

add_executable(${PROJECT_NAME} ${SRC})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
