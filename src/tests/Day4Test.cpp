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
    subject.parseItem("[1518-04-21 23:55] Guard #3331 begins shift");
    subject.parseItem("[1518-06-12 00:02] Guard #3109 begins shift");

    subject.sortItems();

    EXPECT_EQ("[1518-04-21 00:04] Guard #3331 begins shift", subject.orderedItems.at(0));
    EXPECT_EQ("[1518-04-21 00:57] wakes up", subject.orderedItems.at(1));
    EXPECT_EQ("[1518-04-21 23:55] Guard #3331 begins shift", subject.orderedItems.at(2));
    EXPECT_EQ("[1518-06-12 00:02] Guard #3109 begins shift", subject.orderedItems.at(3));
    EXPECT_EQ("[1518-09-03 00:12] falls asleep", subject.orderedItems.at(4));
    EXPECT_EQ("[1518-10-29 00:51] falls asleep", subject.orderedItems.at(5));
}

TEST_F(Day4Test, TheNumberOfMinutesTheGuardsHaveBeenAsleepAreRecorded) {
    subject.parseItem("[1518-11-01 00:00] Guard #10 begins shift");
    subject.parseItem("[1518-11-01 00:05] falls asleep");
    subject.parseItem("[1518-11-01 00:25] wakes up");

    subject.accumulateGuardSleepTimes();

    EXPECT_EQ(20, subject.guardSleepTimes["10"]);
}

TEST_F(Day4Test, TheGuardWithTheLongestSleepTimeWillBeFound) {
    subject.parseItem("[1518-11-01 00:00] Guard #1093 begins shift");
    subject.parseItem("[1518-11-01 00:05] falls asleep");
    subject.parseItem("[1518-11-01 00:25] wakes up");
    subject.parseItem("[1518-11-01 00:26] Guard #99 begins shift");
    subject.parseItem("[1518-11-01 00:27] falls asleep");
    subject.parseItem("[1518-11-01 00:28] wakes up");

    subject.accumulateGuardSleepTimes();

    EXPECT_EQ("1093", subject.getSleepiestGuard());
}

TEST_F(Day4Test, TheMinuteSpentMostAsleepCanBeFound) {
    subject.parseItem("[1518-11-01 00:00] Guard #43 begins shift");
    subject.parseItem("[1518-11-01 00:05] falls asleep");
    subject.parseItem("[1518-11-01 00:25] wakes up");
    subject.parseItem("[1518-11-02 00:00] Guard #43 begins shift");
    subject.parseItem("[1518-11-02 00:24] falls asleep");
    subject.parseItem("[1518-11-02 00:30] wakes up");

    subject.accumulateGuardSleepTimes();

    EXPECT_EQ("24", subject.getSleepiestMinute("43"));
}

TEST_F(Day4Test, TheMostFrequentlyAsleepMinuteCanBeFound) {
    subject.parseItem("[1518-11-01 00:00] Guard #10 begins shift");
    subject.parseItem("[1518-11-01 00:05] falls asleep");
    subject.parseItem("[1518-11-01 00:25] wakes up");
    subject.parseItem("[1518-11-01 00:30] falls asleep");
    subject.parseItem("[1518-11-01 00:55] wakes up");
    subject.parseItem("[1518-11-01 23:58] Guard #99 begins shift");
    subject.parseItem("[1518-11-02 00:40] falls asleep");
    subject.parseItem("[1518-11-02 00:50] wakes up");
    subject.parseItem("[1518-11-03 00:05] Guard #10 begins shift");
    subject.parseItem("[1518-11-03 00:24] falls asleep");
    subject.parseItem("[1518-11-03 00:29] wakes up");
    subject.parseItem("[1518-11-04 00:02] Guard #99 begins shift");
    subject.parseItem("[1518-11-04 00:36] falls asleep");
    subject.parseItem("[1518-11-04 00:46] wakes up");
    subject.parseItem("[1518-11-05 00:03] Guard #99 begins shift");
    subject.parseItem("[1518-11-05 00:45] falls asleep");
    subject.parseItem("[1518-11-05 00:55] wakes up");

    subject.accumulateGuardSleepTimes();
    subject.findMostFrequentlyAsleepMinute();

    EXPECT_EQ("99", subject.guardWithMostFrequentlyAsleepMinute);
    EXPECT_EQ("45", subject.mostFrequentlyAsleepMinute);
}
