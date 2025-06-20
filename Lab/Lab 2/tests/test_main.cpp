#include "utils.h"
#include <gtest/gtest.h>

// Тесты для фильтрации чисел без нуля в двоичном виде
TEST(FilterTest, BasicTest) {
    std::vector<__int16> input = {1, 3, 7, 15, 31, 0, -1, 2};
    std::vector<__int16> expected = {1, 3, 7, 15, 31};
    EXPECT_EQ(filterPositiveNoZeroBinary(input), expected);
}

TEST(FilterTest, EmptyInput) {
    std::vector<__int16> input = {};
    std::vector<__int16> expected = {};
    EXPECT_EQ(filterPositiveNoZeroBinary(input), expected);
}

// Тесты для Фибоначчи
TEST(FibonacciTest, BasicTest) {
    EXPECT_EQ(getFibonacciSequence(0), std::vector<int>({}));
    EXPECT_EQ(getFibonacciSequence(1), std::vector<int>({0}));
    EXPECT_EQ(getFibonacciSequence(5), std::vector<int>({0, 1, 1, 2, 3}));
}
