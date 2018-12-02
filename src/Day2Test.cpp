#include <gtest/gtest.h>
#include "Day2.h"
#include <string>

using namespace std;

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

TEST(Day2Test, WhenAnIdContainsTwoTriplesThenItOnlyCountsOnce) {
    Day2 subject;

    subject.scanId("ababab");

    EXPECT_EQ(1, subject.getTripleCount());
}

TEST(Day2Test, WhenMultipleIdsAreScannedThenTheCountsAreAccumulated) {
    Day2 subject;

    subject.scanId("bababc");
    subject.scanId("bababc");

    EXPECT_EQ(2, subject.getDoubleCount());
    EXPECT_EQ(2, subject.getTripleCount());
}

TEST(Day2Test, TheChecksumWillBeTheMultiplicationOfTheDoubleAndTripleCount) {
    Day2 subject;

    subject.scanId("bababc");
    subject.scanId("bababc");

    EXPECT_EQ(4, subject.getChecksum());
}

TEST(Day2Test, WhenTwoIdsAreIdenticalThenTheBoxesAreNotCorrect) {
    Day2 subject;

    string matchingId = subject.getMatchingId("abcdef", "abcdef");

    EXPECT_EQ("", matchingId);
}

TEST(Day2Test, WhenTwoIdsHaveMoreThanOneDifferentCharacterThenTheBoxesAreNotCorrect) {
    Day2 subject;

    string matchingId = subject.getMatchingId("abcdef", "ghijkl");

    EXPECT_EQ("", matchingId);
}

TEST(Day2Test, WhenOnlyOneCharacterIsDifferentBetweenIdsThenTheIdsAreCorrectAndTheCommonCharactersAreReturned) {
    Day2 subject;

    string matchingId = subject.getMatchingId("abcdef", "abcdeg");

    EXPECT_EQ("abcde", matchingId);
}
