#include <gtest/gtest.h>
#include "Day6.h"

class Day6Test : public ::testing::Test {
protected:
    Day6 subject;
};

TEST_F(Day6Test, TheLargestFiniteAreaCanBeFound) {
    subject.parseItem("1, 1");
    subject.parseItem("1, 6");
    subject.parseItem("8, 3");
    subject.parseItem("3, 4");
    subject.parseItem("5, 5");
    subject.parseItem("8, 9");

    EXPECT_EQ(17, subject.getLargestFiniteArea());
}