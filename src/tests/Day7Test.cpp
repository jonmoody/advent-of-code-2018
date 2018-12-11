#include <gtest/gtest.h>
#include "Day7.h"

class Day7Test : public ::testing::Test {
protected:
    Day7 subject;
};

TEST_F(Day7Test, TheCorrectOrderOfStepsCanBeDetermined) {
    subject.parseItem("Step C must be finished before step A can begin.");
    subject.parseItem("Step C must be finished before step F can begin.");
    subject.parseItem("Step A must be finished before step B can begin.");
    subject.parseItem("Step A must be finished before step D can begin.");
    subject.parseItem("Step B must be finished before step E can begin.");
    subject.parseItem("Step D must be finished before step E can begin.");
    subject.parseItem("Step F must be finished before step E can begin.");

    EXPECT_EQ("CABDFE", subject.getOrder());
}