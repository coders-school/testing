add_library(${PROJECT_NAME}-catch STATIC catch.cpp)
set_target_properties(${PROJECT_NAME}-catch PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

set(COMPILER_FLAGS -Wall -Wextra -Werror -Wpedantic -Wconversion -O0 -g)

add_executable(CatchMain CatchMain.cpp)
set_target_properties(CatchMain PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
target_compile_options(CatchMain PRIVATE ${COMPILER_FLAGS})

add_executable(ScoreTests ScoreTests.cpp)
set_target_properties(ScoreTests PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)
target_compile_options(ScoreTests PRIVATE ${COMPILER_FLAGS})

target_link_libraries(CatchMain PRIVATE ${PROJECT_NAME}-catch ${PROJECT_NAME}-lib)
target_link_libraries(ScoreTests PRIVATE ${PROJECT_NAME}-catch ${PROJECT_NAME}-lib)
