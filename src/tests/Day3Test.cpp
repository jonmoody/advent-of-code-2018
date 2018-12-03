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

    EXPECT_EQ(2, subject.pointsTaken.at(0).x);
    EXPECT_EQ(2, subject.pointsTaken.at(0).y);

    EXPECT_EQ(3, subject.pointsTaken.at(1).x);
    EXPECT_EQ(2, subject.pointsTaken.at(1).y);

    EXPECT_EQ(2, subject.pointsTaken.at(2).x);
    EXPECT_EQ(3, subject.pointsTaken.at(2).y);

    EXPECT_EQ(3, subject.pointsTaken.at(3).x);
    EXPECT_EQ(3, subject.pointsTaken.at(3).y);
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
