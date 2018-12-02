#include <gtest/gtest.h>
#include "Day2.h"

TEST(Day2Test, WhenAnIdDoesNotContainTheSameLetterTwiceThenItDoesNotHaveAnyDoubles) {
    Day2 subject;

    subject.scanId("abcdef");

    EXPECT_EQ(0, subject.getDoubleCount());
}

TEST(Day2Test, WhenAnIdDoesNotContainTheSameLetterThreeTimesThenItDoesNotHaveAnyTriples) {
    Day2 subject;

    subject.scanId("abcdef");

    EXPECT_EQ(0, subject.getTripleCount());
}

TEST(Day2Test, WhenAnIdContainsALetterTwiceThenItIncreasesTheDoubleCount) {
    Day2 subject;

    subject.scanId("abcdee");

    EXPECT_EQ(1, subject.getDoubleCount());
}
