#include <gtest/gtest.h>
#include "Day3.h"
#include <string>
#include <vector>

using namespace std;

class Day3Test : public ::testing::Test {
protected:
    Day3 subject;
};

TEST_F(Day3Test, TheInputCanBeParsedCorrectly) {
    string claimInput = "#1 @ 3,4: 5x6";

    Claim claim = subject.parseClaim(claimInput);

    EXPECT_EQ(3, claim.left);
    EXPECT_EQ(4, claim.top);
    EXPECT_EQ(5, claim.width);
    EXPECT_EQ(6, claim.height);
}

TEST_F(Day3Test, ThePointsTakenAreRecorded) {
    subject.parseClaim("#1 @ 2,2: 2x2");

    EXPECT_TRUE(subject.pointsTaken.find("2,2") != subject.pointsTaken.end());
    EXPECT_TRUE(subject.pointsTaken.find("2,3") != subject.pointsTaken.end());
    EXPECT_TRUE(subject.pointsTaken.find("3,2") != subject.pointsTaken.end());
    EXPECT_TRUE(subject.pointsTaken.find("3,3") != subject.pointsTaken.end());
}

TEST_F(Day3Test, WhenThereAreNoPointsThatOverlapThenThereAreNoPointsRecorded) {
    subject.parseClaim("#1 @ 2,2: 1x1");
    subject.parseClaim("#1 @ 3,3: 1x1");

    EXPECT_EQ(0, subject.pointsOverlapping.size());
}

TEST_F(Day3Test, WhenThereIsAPointThatOverlapsThenItIsRecorded) {
    subject.parseClaim("#1 @ 2,2: 1x1");
    subject.parseClaim("#1 @ 2,2: 1x1");

    EXPECT_EQ(1, subject.pointsOverlapping.size());
}

TEST_F(Day3Test, PointsThatOverlapAreNotDuplicated) {
    subject.parseClaim("#1 @ 2,2: 1x1");
    subject.parseClaim("#1 @ 2,2: 1x1");
    subject.parseClaim("#1 @ 2,2: 1x1");

    EXPECT_EQ(1, subject.pointsOverlapping.size());
}

TEST_F(Day3Test, TheNumberOfOverlappingSquaresCanBeCalculated) {
    subject.parseClaim("#1 @ 2,2: 2x2");
    subject.parseClaim("#1 @ 3,2: 2x2");

    EXPECT_EQ(2, subject.getNumberOfOverlappingSquares());
}

TEST_F(Day3Test, TheIdOfTheUntouchedClaimIsKept) {
    subject.parseClaim("#1 @ 2,2: 2x2");
    subject.parseClaim("#2 @ 3,2: 2x2");
    subject.parseClaim("#3 @ 10,10: 2x2");
    subject.parseClaim("#4 @ 3,2: 2x2");
    subject.parseClaim("#5 @ 3,2: 2x2");

    EXPECT_EQ(3, subject.getUntouchedClaimId());
}
