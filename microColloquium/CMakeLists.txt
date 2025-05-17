# CMakeLists.txt
cmake_minimum_required(VERSION 3.14)
project(filesystem_visitor_multithreaded)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

add_executable(main src/main.cpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit_tests test/unit_tests.cpp)
target_link_libraries(unit_tests GTest::GTest GTest::Main)

add_executable(e2e_tests test/e2e_tests.cpp)
target_link_libraries(e2e_tests GTest::GTest GTest::Main)
