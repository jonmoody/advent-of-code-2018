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

TEST(Day2Test, WhenAnIdContainsALetterThreeTimesThenItIncreasesTheTripleCount) {
    Day2 subject;

    subject.scanId("abcccd");

    EXPECT_EQ(1, subject.getTripleCount());
}

TEST(Day2Test, WhenAnIdContainsADoubleAndATripleThenItCountsForBoth) {
    Day2 subject;

    subject.scanId("bababc");

    EXPECT_EQ(1, subject.getDoubleCount());
    EXPECT_EQ(1, subject.getTripleCount());
}

TEST(Day2Test, WhenAnIdContainsTwoDoublesThenItOnlyCountsOnce) {
    Day2 subject;

    subject.scanId("aabcdd");

    EXPECT_EQ(1, subject.getDoubleCount());
}
