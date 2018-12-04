#include <gtest/gtest.h>
#include "Day4.h"

class Day4Test : public ::testing::Test {
protected:
    Day4 subject;
};

TEST_F(Day4Test, TheInputIsOrganizedInChronologicalOrder) {
    subject.parseItem("[1518-04-21 00:57] wakes up");
    subject.parseItem("[1518-09-03 00:12] falls asleep");
    subject.parseItem("[1518-04-21 00:04] Guard #3331 begins shift");
    subject.parseItem("[1518-10-29 00:51] falls asleep");
    subject.parseItem("[1518-06-12 00:02] Guard #3109 begins shift");

    subject.sortItems();

    EXPECT_EQ("[1518-04-21 00:04] Guard #3331 begins shift", subject.orderedItems.at(0));
    EXPECT_EQ("[1518-04-21 00:57] wakes up", subject.orderedItems.at(1));
    EXPECT_EQ("[1518-06-12 00:02] Guard #3109 begins shift", subject.orderedItems.at(2));
    EXPECT_EQ("[1518-09-03 00:12] falls asleep", subject.orderedItems.at(3));
    EXPECT_EQ("[1518-10-29 00:51] falls asleep", subject.orderedItems.at(4));
}

TEST_F(Day4Test, TheNumberOfMinutesTheGuardsHaveBeenAsleepAreRecorded) {
    subject.parseItem("[1518-11-01 00:00] Guard #10 begins shift");
    subject.parseItem("[1518-11-01 00:05] falls asleep");
    subject.parseItem("[1518-11-01 00:25] wakes up");

    subject.accumulateGuardSleepTimes();

    EXPECT_EQ(20, subject.guardSleepTimes["#10"]);
}

TEST_F(Day4Test, TheGuardWithTheLongestSleepTimeWillBeFound) {
    subject.parseItem("[1518-11-01 00:00] Guard #10 begins shift");
    subject.parseItem("[1518-11-01 00:05] falls asleep");
    subject.parseItem("[1518-11-01 00:25] wakes up");
    subject.parseItem("[1518-11-01 00:26] Guard #99 begins shift");
    subject.parseItem("[1518-11-01 00:27] falls asleep");
    subject.parseItem("[1518-11-01 00:28] wakes up");

    subject.accumulateGuardSleepTimes();

    EXPECT_EQ("#10", subject.getSleepiestGuard());
}