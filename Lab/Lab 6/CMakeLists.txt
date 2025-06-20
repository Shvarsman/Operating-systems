enable_testing()
find_package(GTest REQUIRED)

add_executable(Tests tests/tests.cpp src/utils.cpp)
target_link_libraries(Tests GTest::GTest GTest::Main pthread)

add_test(NAME RunTests COMMAND Tests)
