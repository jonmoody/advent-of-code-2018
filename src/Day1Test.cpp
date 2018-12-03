#include <gtest/gtest.h>
#include "Day1.h"

class Day1Test : public ::testing::Test {
protected:
    Day1 subject;
};

TEST_F(Day1Test, WhenANegativeSignIsFoundInTheFrequencyThenItIsSubtracted) {
    EXPECT_EQ(-10, subject.getSingleFrequency("-10"));
}

TEST_F(Day1Test, WhenAPositiveSignIsFoundInTheFrequencyThenItIsAdded) {
    EXPECT_EQ(50, subject.getSingleFrequency("+50"));
}

TEST_F(Day1Test, WhenMultipleFrequenciesAreAddedThenItWillKeepARunningTotal) {
    subject.valuesFromFile.push_back(-1);
    subject.valuesFromFile.push_back(1);

    subject.findFrequencyMatch();

    EXPECT_EQ(0, subject.getTotalFrequency());
}

TEST_F(Day1Test, WhenAFrequencyMatchIsNotFoundThenItWillLoopThroughTheListUntilItDoes) {
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