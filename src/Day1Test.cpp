#include <gtest/gtest.h>

TEST(Day1Test, APassingTest)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}