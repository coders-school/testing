cmake_minimum_required(VERSION 3.10)

project(bowling)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_FILES tests.ut.cpp)

add_library(lib STATIC ${TEST_FILES})
add_executable(${PROJECT_NAME}-ut catchMain.cpp tests.ut.cpp)
#add_executable(${PROJECT_NAME}-ut tests.ut.cpp)
#target_compile_options( -Wall -Wextra -Werror -pedantic )

target_link_libraries(${PROJECT_NAME}-ut lib)

enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)
