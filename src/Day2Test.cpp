#include <gtest/gtest.h>
#include "Day2.h"

TEST(Day2Test, WhenAnIdDoesNotContainTheSameLetterTwiceThenItDoesNotHaveAnyDoubles) {
    Day2 subject;

    subject.scanId("abcdef");

    EXPECT_EQ(0, subject.getDoubleCount());
}
