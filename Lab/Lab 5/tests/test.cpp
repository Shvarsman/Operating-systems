#include <gtest/gtest.h>
#include "utils.h"

TEST(PrimeTest, Basic) {
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(1));
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_FALSE(isPrime(4));
    EXPECT_TRUE(isPrime(5));
    EXPECT_FALSE(isPrime(9));
    EXPECT_TRUE(isPrime(11));
    EXPECT_FALSE(isPrime(100));
    EXPECT_TRUE(isPrime(9973)); // Большое простое число
}
