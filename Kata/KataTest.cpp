#include <gtest/gtest.h>

TEST(KataTest, APassingTest)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}