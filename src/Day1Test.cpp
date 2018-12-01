#include <gtest/gtest.h>
#include "Day1.h"

TEST(Day1Test, WhenANegativeSignIsFoundInTheFrequencyThenItIsSubtracted)
{
    Day1 subject;

    subject.addFrequency("-10");

    EXPECT_EQ(-10, subject.getFrequency());
}

TEST(Day1Test, WhenAPositiveSignIsFoundInTheFrequencyThenItIsAdded) {
    Day1 subject;

    subject.addFrequency("+50");

    EXPECT_EQ(50, subject.getFrequency());
}

TEST(Day1Test, WhenMultipleFrequenciesAreAddedThenItWillKeepARunningTotal) {
    Day1 subject;

    subject.addFrequency("-10");
    subject.addFrequency("+30");

    EXPECT_EQ(20, subject.getFrequency());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}