#include <gtest/gtest.h>
#include "functions.h"

TEST(MultiplesOfFiveTest, BasicTest) {
    int arr[] = {5, 10, 15, 3, 7};
    std::vector<int> expected = {5, 10, 15};
    EXPECT_EQ(getMultiplesOfFive(arr, 5), expected);
}

TEST(MultiplesOfFiveTest, NoMultiples) {
    int arr[] = {1, 2, 3, 4, 6};
    std::vector<int> expected = {};
    EXPECT_EQ(getMultiplesOfFive(arr, 5), expected);
}

TEST(MultiplesOfFiveTest, EmptyArray) {
    int* arr = nullptr;
    std::vector<int> expected = {};
    EXPECT_EQ(getMultiplesOfFive(arr, 0), expected);
}

TEST(MultiplesOfFiveTest, AllAreMultiples) {
    int arr[] = {10, 20, 30, 40};
    std::vector<int> expected = {10, 20, 30, 40};
    EXPECT_EQ(getMultiplesOfFive(arr, 4), expected);
}

TEST(MultiplesOfFiveTest, NegativeNumbers) {
    int arr[] = {-5, -10, -3, 5};
    std::vector<int> expected = {-5, -10, 5};
    EXPECT_EQ(getMultiplesOfFive(arr, 4), expected);
}
