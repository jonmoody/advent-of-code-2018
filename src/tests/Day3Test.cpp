#include <gtest/gtest.h>
#include "Day3.h"
#include <string>
#include <vector>

using namespace std;

class Day3Test : public ::testing::Test {
protected:
    Day3 subject;
};

TEST_F(Day3Test, TheInputCanBeParsedCorrectly) {
    string claimInput = "#1 @ 3,4: 5x6";

    Claim claim = subject.parseClaim(claimInput);

    EXPECT_EQ(3, claim.left);
    EXPECT_EQ(4, claim.top);
    EXPECT_EQ(5, claim.width);
    EXPECT_EQ(6, claim.height);
}
