
cmake_minimum_required(VERSION 3.10)
project(University)

set(SRC )
set(testFile ../test/bowling_test.cpp ../test/catch_amalgamated.cpp)
set(COMP_FLAGS -Wall -Wextra -pedantic -Wconversion)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
add_executable(${PROJECT_NAME}-ut ${testFile} ${SRC})

target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)

target_compile_options(${PROJECT_NAME} PRIVATE ${COMP_FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${COMP_FLAGS})

set_target_properties(${PROJECT_NAME} PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)                  
set_target_properties(${PROJECT_NAME}-lib PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)
set_target_properties(${PROJECT_NAME}-ut PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)