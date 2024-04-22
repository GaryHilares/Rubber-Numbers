#include "../include/RubberNumbers/RubberIntegers.hpp"
#include <gtest/gtest.h>
using namespace RubberNumbers;

TEST(EqualsOp, Zero)
{
    ASSERT_EQ(RubberInt(), RubberInt());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}