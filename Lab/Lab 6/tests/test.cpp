#include <gtest/gtest.h>
#include "utils.h"

TEST(StringValidationTest, Basic) {
    EXPECT_TRUE(isValidString("abc", 'a', 'z'));
    EXPECT_FALSE(isValidString("abcd", 'a', 'c'));
    EXPECT_TRUE(isValidString("", 'a', 'z'));  // Пустая строка считается валидной
    EXPECT_TRUE(isValidString("A1b", '0', 'z'));  // цифры и буквы
    EXPECT_FALSE(isValidString("Hello!", 'a', 'z'));
}

TEST(MultiplyLengthsTest, Basic) {
    EXPECT_EQ(multiplyLengths({}), 1); // пустой массив
    EXPECT_EQ(multiplyLengths({"a"}), 1);
    EXPECT_EQ(multiplyLengths({"ab", "c", "def"}), 2 * 1 * 3);
    EXPECT_EQ(multiplyLengths({"test", "test"}), 4 * 4);
}
