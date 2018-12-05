#include <gtest/gtest.h>
#include "Day5.h"
#include <string>

using namespace std;

class Day5Test : public ::testing::Test {
protected:
    Day5 subject;
};

TEST_F(Day5Test, TheInputCanBeReduced) {
    string result = subject.parseItem("dabAcCaCBAcCcaDA");

    EXPECT_EQ("dabCBAcaDA", result);
}

TEST_F(Day5Test, ThePolymerCanBeReducedFurtherByRemovingUnits) {
    int result = subject.findSmallestPolymerLength("dabAcCaCBAcCcaDA");

    EXPECT_EQ(4, result);
}