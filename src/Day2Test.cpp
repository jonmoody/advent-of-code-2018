#include <gtest/gtest.h>
#include "Day2.h"
#include <string>

using namespace std;

class Day2Test : public ::testing::Test {
protected:
    Day2 subject;
};

TEST_F(Day2Test, WhenAnIdDoesNotContainTheSameLetterTwiceThenItDoesNotHaveAnyDoubles) {
    subject.scanId("abcdef");

    EXPECT_EQ(0, subject.getDoubleCount());
}

TEST_F(Day2Test, WhenAnIdDoesNotContainTheSameLetterThreeTimesThenItDoesNotHaveAnyTriples) {
    subject.scanId("abcdef");

    EXPECT_EQ(0, subject.getTripleCount());
}

TEST_F(Day2Test, WhenAnIdContainsALetterTwiceThenItIncreasesTheDoubleCount) {
    subject.scanId("abcdee");

    EXPECT_EQ(1, subject.getDoubleCount());
}

TEST_F(Day2Test, WhenAnIdContainsALetterThreeTimesThenItIncreasesTheTripleCount) {
    subject.scanId("abcccd");

    EXPECT_EQ(1, subject.getTripleCount());
}

TEST_F(Day2Test, WhenAnIdContainsADoubleAndATripleThenItCountsForBoth) {
    subject.scanId("bababc");

    EXPECT_EQ(1, subject.getDoubleCount());
    EXPECT_EQ(1, subject.getTripleCount());
}

TEST_F(Day2Test, WhenAnIdContainsTwoDoublesThenItOnlyCountsOnce) {
    subject.scanId("aabcdd");

    EXPECT_EQ(1, subject.getDoubleCount());
}

TEST_F(Day2Test, WhenAnIdContainsTwoTriplesThenItOnlyCountsOnce) {
    subject.scanId("ababab");

    EXPECT_EQ(1, subject.getTripleCount());
}

TEST_F(Day2Test, WhenMultipleIdsAreScannedThenTheCountsAreAccumulated) {
    subject.scanId("bababc");
    subject.scanId("bababc");

    EXPECT_EQ(2, subject.getDoubleCount());
    EXPECT_EQ(2, subject.getTripleCount());
}

TEST_F(Day2Test, TheChecksumWillBeTheMultiplicationOfTheDoubleAndTripleCount) {
    subject.scanId("bababc");
    subject.scanId("bababc");

    EXPECT_EQ(4, subject.getChecksum());
}

TEST_F(Day2Test, WhenTwoIdsAreIdenticalThenTheBoxesAreNotCorrect) {
    string matchingId = subject.getMatchingId("abcdef", "abcdef");

    EXPECT_EQ("", matchingId);
}

TEST_F(Day2Test, WhenTwoIdsHaveMoreThanOneDifferentCharacterThenTheBoxesAreNotCorrect) {
    string matchingId = subject.getMatchingId("abcdef", "ghijkl");

    EXPECT_EQ("", matchingId);
}

TEST_F(Day2Test, WhenOnlyOneCharacterIsDifferentBetweenIdsThenTheIdsAreCorrectAndTheCommonCharactersAreReturned) {
    string matchingId = subject.getMatchingId("abcdef", "abcdeg");

    EXPECT_EQ("abcde", matchingId);
}

TEST_F(Day2Test, AllIdsInTheListWillLoopThroughToFindAMatchingId) {
    subject.ids.push_back("abcdef");
    subject.ids.push_back("ghijkl");
    subject.ids.push_back("zzzzzz");
    subject.ids.push_back("abcdeg");

    string matchingId = subject.findMatch();

    EXPECT_EQ("abcde", matchingId);
}
