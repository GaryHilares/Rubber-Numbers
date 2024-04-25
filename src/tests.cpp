#include "../include/RubberNumbers/RubberIntegers.hpp"
#include <gtest/gtest.h>
using namespace RubberNumbers;

TEST(DefaultConstructor, EqualsZero)
{
    ASSERT_EQ(RubberInt().toString(), "0");
}

TEST(StringConstructor, PositiveSmallIntegers)
{
    ASSERT_EQ(RubberInt("5").toString(), "5");
    ASSERT_EQ(RubberInt("12").toString(), "12");
    ASSERT_EQ(RubberInt("25").toString(), "25");
    ASSERT_EQ(RubberInt("200").toString(), "200");
}

TEST(StringConstructor, PositiveBigIntegers)
{
    ASSERT_EQ(RubberInt("2147483647").toString(), "2147483647");
    ASSERT_EQ(RubberInt("2147483648").toString(), "2147483648");
    ASSERT_EQ(RubberInt("9223372036854775807").toString(), "9223372036854775807");
    ASSERT_EQ(RubberInt("9223372036854775808").toString(), "9223372036854775808");
    ASSERT_EQ(RubberInt("18446744073709551615").toString(), "18446744073709551615");
    ASSERT_EQ(RubberInt("18446744073709551616").toString(), "18446744073709551616");
    ASSERT_EQ(RubberInt("9999999999999999999").toString(), "9999999999999999999");
    ASSERT_EQ(RubberInt("2234890932480083249234").toString(), "2234890932480083249234");
}

TEST(StringConstructor, NonPositiveSmallIntegers)
{
    ASSERT_EQ(RubberInt("0").toString(), "0");
    ASSERT_EQ(RubberInt("-234").toString(), "-234");
    ASSERT_EQ(RubberInt("-255238").toString(), "-255238");
    ASSERT_EQ(RubberInt("-13280").toString(), "-13280");
}

TEST(StringConstructor, NonPositiveBigIntegers)
{
    ASSERT_EQ(RubberInt("-234").toString(), "-234");
    ASSERT_EQ(RubberInt("-13280").toString(), "-13280");
    ASSERT_EQ(RubberInt("-255238").toString(), "-255238");
    ASSERT_EQ(RubberInt("-2147483648").toString(), "-2147483648");
    ASSERT_EQ(RubberInt("-2147483649").toString(), "-2147483649");
    ASSERT_EQ(RubberInt("-1849308140810481431840").toString(), "-1849308140810481431840");
    ASSERT_EQ(RubberInt("-999999999999999999999999").toString(), "-999999999999999999999999");
}

TEST(IntTypeConstructor, PositiveIntegers)
{
    ASSERT_EQ(RubberInt(5).toString(), "5");
    ASSERT_EQ(RubberInt(12).toString(), "12");
    ASSERT_EQ(RubberInt(1233123).toString(), "1233123");
}

TEST(IntTypeConstructor, NonPositiveIntegers)
{
    ASSERT_EQ(RubberInt(0).toString(), "0");
    ASSERT_EQ(RubberInt(-1).toString(), "-1");
    ASSERT_EQ(RubberInt(-55).toString(), "-55");
    ASSERT_EQ(RubberInt(-90980).toString(), "-90980");
    ASSERT_EQ(RubberInt(9223372036854775807LL).toString(), "9223372036854775807");
}

TEST(EqualsOperator, EqualPositiveIntegers)
{
    ASSERT_EQ(RubberInt(5), RubberInt(5));
    ASSERT_EQ(RubberInt(12), RubberInt(12));
    ASSERT_EQ(RubberInt(1233123), RubberInt(1233123));
}

TEST(EqualsOperator, DifferentPositiveIntegers)
{
    ASSERT_FALSE(RubberInt(5) == RubberInt(12));
    ASSERT_FALSE(RubberInt(12) == RubberInt(32));
    ASSERT_FALSE(RubberInt(1233123) == RubberInt(234));
}

TEST(EqualsOperator, EqualNonPositiveIntegers)
{
    ASSERT_EQ(RubberInt(0), RubberInt(0));
    ASSERT_EQ(RubberInt(-5), RubberInt(-5));
    ASSERT_EQ(RubberInt(-42), RubberInt(-42));
    ASSERT_EQ(RubberInt(-12321), RubberInt(-12321));
}

TEST(EqualsOperator, DifferentNonPositiveIntegers)
{
    ASSERT_FALSE(RubberInt(0) == RubberInt(-14));
    ASSERT_FALSE(RubberInt(-234) == RubberInt(-231));
    ASSERT_FALSE(RubberInt(-2) == RubberInt(-1));
    ASSERT_FALSE(RubberInt(-2147483648) == RubberInt(0));
}

TEST(EqualsOperator, SameValueDifferentSign)
{
    ASSERT_FALSE(RubberInt(14) == RubberInt(-14));
    ASSERT_FALSE(RubberInt(234) == RubberInt(-234));
    ASSERT_FALSE(RubberInt(-2) == RubberInt(2));
    ASSERT_FALSE(RubberInt(-2147483648) == RubberInt(2147483648));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}