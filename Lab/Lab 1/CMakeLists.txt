cmake_minimum_required(VERSION 3.14)
project(UnitTests)

include_directories(${PROJECT_SOURCE_DIR})

enable_testing()
add_subdirectory(googletest)

add_executable(runner tests.cpp functions.cpp)
target_link_libraries(runner gtest gtest_main pthread)

add_test(NAME UnitTests COMMAND runner)
