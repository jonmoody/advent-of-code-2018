#include <gtest/gtest.h>
#include "Day1.h"

TEST(Day1Test, WhenANegativeSignIsFoundInTheFrequencyThenItIsSubtracted) {
    Day1 subject;

    EXPECT_EQ(-10, subject.getSingleFrequency("-10"));
}

TEST(Day1Test, WhenAPositiveSignIsFoundInTheFrequencyThenItIsAdded) {
    Day1 subject;

    EXPECT_EQ(50, subject.getSingleFrequency("+50"));
}

TEST(Day1Test, WhenMultipleFrequenciesAreAddedThenItWillKeepARunningTotal) {
    Day1 subject;

    subject.valuesFromFile.push_back(-1);
    subject.valuesFromFile.push_back(1);

    subject.findFrequencyMatch();

    EXPECT_EQ(0, subject.getTotalFrequency());
}

TEST(Day1Test, WhenAFrequencyMatchIsNotFoundThenItWillLoopThroughTheListUntilItDoes) {
    Day1 subject;

    subject.valuesFromFile.push_back(3);
    subject.valuesFromFile.push_back(3);
    subject.valuesFromFile.push_back(4);
    subject.valuesFromFile.push_back(-2);
    subject.valuesFromFile.push_back(-4);

    subject.findFrequencyMatch();

    EXPECT_EQ(10, subject.getTotalFrequency());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}