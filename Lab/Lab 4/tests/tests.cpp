#include <gtest/gtest.h>
#include "utils.h"

TEST(MessageValidationTest, ValidInput) {
    EXPECT_TRUE(isValidMessage("A"));
    EXPECT_TRUE(isValidMessage("B"));
}

TEST(MessageValidationTest, InvalidInput) {
    EXPECT_FALSE(isValidMessage(""));
    EXPECT_FALSE(isValidMessage("C"));
    EXPECT_FALSE(isValidMessage("AB"));
    EXPECT_FALSE(isValidMessage("a"));
}
