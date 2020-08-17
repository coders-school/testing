cmake_minimum_required(VERSION 3.10)

project(bowling)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/example.cpp)

set(TESTS
    tests/example-ut.cpp)

set(FLAGS -Wall -Wextra -pedantic -Wconversion -Werror)

include_directories(inc)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

add_executable(${PROJECT_NAME}-ut tests/test_main.cpp ${TESTS})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
