cmake_minimum_required(VERSION 3.0.0)
project(Bowling)

add_subdirectory(tests)

set(SRC src/Score.cpp)
set(COMPILER_FLAGS -Wall -Wextra -Werror -Wpedantic -Wconversion -O0 -g)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
set_target_properties(${PROJECT_NAME}-lib PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${COMPILER_FLAGS})

add_executable(${PROJECT_NAME} src/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILER_FLAGS})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

enable_testing()
add_test(NAME MyTests COMMAND ScoreTests)
