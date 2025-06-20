#include <gtest/gtest.h>
#include "functions.h"

TEST(PrimeTest, Basic) {
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_FALSE(isPrime(4));
    EXPECT_TRUE(isPrime(5));
    EXPECT_FALSE(isPrime(1));
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(-3));
}

TEST(CountPositiveTest, Basic) {
    EXPECT_EQ(countPositiveElements({1, -2, 3, 0, 4}), 3);
    EXPECT_EQ(countPositiveElements({-1, -2, -3}), 0);
    EXPECT_EQ(countPositiveElements({}), 0);
    EXPECT_EQ(countPositiveElements({10}), 1);
}

TEST(FilterPrimesTest, Basic) {
    auto input = std::vector<long>{2, 3, 4, 5, 6, 7, 8};
    auto result = filterPrimesUpToK(input, 3);
    EXPECT_EQ(result, std::vector<long>({2, 3, 5}));

    result = filterPrimesUpToK(input, 10);
    EXPECT_EQ(result, std::vector<long>({2, 3, 5, 7, 1, 1, 1, 1}));
}
