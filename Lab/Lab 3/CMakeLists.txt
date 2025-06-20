cmake_minimum_required(VERSION 3.15)
project(ThreadedPrimeFilter)

set(CMAKE_CXX_STANDARD 17)

add_executable(App src/main.cpp src/functions.cpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(Tests tests/tests.cpp src/functions.cpp)
target_link_libraries(Tests GTest::GTest GTest::Main pthread)

add_test(NAME RunTests COMMAND Tests)
