#include "../include/RubberNumbers/RubberIntegers.hpp"
#include <gtest/gtest.h>
using namespace RubberNumbers;

TEST(DefaultConstructor, EqualsZero)
{
    ASSERT_EQ(RubberInt().toString(), "0");
}

TEST(StringConstructor, SmallPositiveInteger)
{
    ASSERT_EQ(RubberInt("5").toString(), "5");
}

TEST(StringConstructor, BigPositiveInteger)
{
    ASSERT_EQ(RubberInt("2234890932480083249234").toString(), "2234890932480083249234");
}

TEST(StringConstructor, Zero)
{
    ASSERT_EQ(RubberInt("0").toString(), "0");
}

TEST(StringConstructor, SmallNegativeInteger)
{
    ASSERT_EQ(RubberInt("-234").toString(), "-234");
}

TEST(StringConstructor, BigNegativeInteger)
{
    ASSERT_EQ(RubberInt("-1849308140810481431840").toString(), "-1849308140810481431840");
}

TEST(IntTypeConstructor, PositiveInteger)
{
    ASSERT_EQ(RubberInt(5).toString(), "5");
}

TEST(IntTypeConstructor, Zero)
{
    ASSERT_EQ(RubberInt(0).toString(), "0");
}

TEST(IntTypeConstructor, NegativeInteger)
{
    ASSERT_EQ(RubberInt(-55).toString(), "-55");
}

TEST(IntTypeConstructor, PositiveLongLongInteger)
{
    ASSERT_EQ(RubberInt(9223372036854775807LL).toString(), "9223372036854775807");
}

TEST(IntTypeConstructor, NegativeLongLongInteger)
{
    ASSERT_EQ(RubberInt(-9223372036854775807LL).toString(), "-9223372036854775807");
}

TEST(EqualsOperator, EqualPositiveIntegers)
{
    ASSERT_EQ(RubberInt(5), RubberInt(5));
}

TEST(EqualsOperator, DifferentPositiveIntegers)
{
    ASSERT_FALSE(RubberInt(5) == RubberInt(12));
}

TEST(EqualsOperator, EqualZeroes)
{
    ASSERT_EQ(RubberInt(0), RubberInt(0));
}

TEST(EqualsOperator, EqualNegativeIntegers)
{
    ASSERT_EQ(RubberInt(-5), RubberInt(-5));
}

TEST(EqualsOperator, DifferentNegativeIntegers)
{
    ASSERT_FALSE(RubberInt(-12) == RubberInt(-5));
}

TEST(EqualsOperator, DifferentSignsSameValue)
{
    ASSERT_FALSE(RubberInt(14) == RubberInt(-14));
}

TEST(EqualsOperator, DifferentSignsDifferentValues)
{
    ASSERT_FALSE(RubberInt(16) == RubberInt(-32));
}

TEST(NotEqualsOperator, EqualPositiveIntegers)
{
    ASSERT_FALSE(RubberInt(5) != RubberInt(5));
}

TEST(NotEqualsOperator, DifferentPositiveIntegers)
{
    ASSERT_TRUE(RubberInt(5) != RubberInt(12));
}

TEST(NotEqualsOperator, EqualZeroes)
{
    ASSERT_FALSE(RubberInt(0) != RubberInt(0));
}

TEST(NotEqualsOperator, EqualNegativeIntegers)
{
    ASSERT_FALSE(RubberInt(-5) != RubberInt(-5));
}

TEST(NotEqualsOperator, DifferentNegativeIntegers)
{
    ASSERT_TRUE(RubberInt(-12) != RubberInt(-5));
}

TEST(NotEqualsOperator, DifferentSignsSameValue)
{
    ASSERT_TRUE(RubberInt(14) != RubberInt(-14));
}

TEST(NotEqualsOperator, DifferentSignsDifferentValues)
{
    ASSERT_TRUE(RubberInt(16) != RubberInt(-32));
}

TEST(GreaterThanOperator, FirstOperandIsGreater)
{
    ASSERT_TRUE(RubberInt(16) > RubberInt(-32));
}

TEST(GreaterThanOperator, OperandsAreEqual)
{
    ASSERT_FALSE(RubberInt(16) > RubberInt(16));
}

TEST(GreaterThanOperator, SecondOperandIsGreater)
{
    ASSERT_FALSE(RubberInt(16) > RubberInt(32));
}

TEST(GreaterThanOrEqualOperator, FirstOperandIsGreater)
{
    ASSERT_TRUE(RubberInt(16) >= RubberInt(-32));
}

TEST(GreaterThanOrEqualOperator, OperandsAreEqual)
{
    ASSERT_TRUE(RubberInt(16) >= RubberInt(16));
}

TEST(GreaterThanOrEqualOperator, SecondOperandIsGreater)
{
    ASSERT_FALSE(RubberInt(16) >= RubberInt(32));
}

TEST(LowerThanOperator, FirstOperandIsLower)
{
    ASSERT_TRUE(RubberInt(-16) < RubberInt(32));
}

TEST(LowerThanOperator, OperandsAreEqual)
{
    ASSERT_FALSE(RubberInt(-16) < RubberInt(-16));
}

TEST(LowerThanOperator, SecondOperandIsLower)
{
    ASSERT_FALSE(RubberInt(16) < RubberInt(10));
}

TEST(LowerThanOrEqualOperator, FirstOperandIsLower)
{
    ASSERT_TRUE(RubberInt(-16) <= RubberInt(32));
}

TEST(LowerThanOrEqualOperator, OperandsAreEqual)
{
    ASSERT_TRUE(RubberInt(-16) <= RubberInt(-16));
}

TEST(LowerThanOrEqualOperator, SecondOperandIsLower)
{
    ASSERT_FALSE(RubberInt(16) <= RubberInt(10));
}

TEST(AdditionOperator, AdditionOfSmallPositiveIntegers)
{
    ASSERT_EQ(RubberInt(10) + RubberInt(16), RubberInt(10 + 16));
}

TEST(AdditionOperator, AdditionOfBigPositiveIntegers)
{
    ASSERT_EQ(RubberInt("1111111111111111111111111") + RubberInt("8888888888888888888888889"), RubberInt("10000000000000000000000000"));
}

TEST(AdditionOperator, AdditionOfComplementaryIntegers)
{
    ASSERT_EQ(RubberInt(18) + RubberInt(-18), RubberInt(0));
}

TEST(AdditionOperator, AdditionOfSmallNegativeIntegers)
{
    ASSERT_EQ(RubberInt(-138) + RubberInt(-143), RubberInt(-138 - 143));
}

TEST(AdditionOperator, AdditionOfBigNegativeIntegers)
{
    ASSERT_EQ(RubberInt("-7777777777777777777777778") + RubberInt("-2222222222222222222222223"), RubberInt("-10000000000000000000000001"));
}

TEST(SubtractionOperator, SubtractionOfSmallPositiveIntegers)
{
    ASSERT_EQ(RubberInt(18) - RubberInt(32), RubberInt(18 - 32));
}

TEST(SubtractionOperator, SubtractionOfBigPositiveIntegers)
{
    ASSERT_EQ(RubberInt("10000000000000000000000000") - RubberInt("999999999999999999999999"), RubberInt("9000000000000000000000001"));
}

TEST(SubtractionOperator, SubtractionOfEqualIntegers)
{
    ASSERT_EQ(RubberInt("103413957157113895137134789") - RubberInt("103413957157113895137134789"), RubberInt(0));
}

TEST(SubtractionOperator, SubtractionOfSmallNegativeIntegers)
{
    ASSERT_EQ(RubberInt(-33) - RubberInt(-34), RubberInt(-33 - -34));
}

TEST(SubtractionOperator, SubtractionOfBigNegativeIntegers)
{
    ASSERT_EQ(RubberInt("-10000000000000000000000000") - RubberInt("-9000000000000000000000000"), RubberInt("-1000000000000000000000000"));
}

TEST(ProductOperator, ProductOfSmallPositiveIntegers)
{
    ASSERT_EQ(RubberInt(134) * RubberInt(1421), RubberInt(134 * 1421));
}

TEST(ProductOperator, ProductOfBigPositiveIntegers)
{
    ASSERT_EQ(RubberInt("1047189371983175913758913795") * RubberInt("112324813095831085115312"), RubberInt("117625350483950967497443969530002453363685442529040"));
}

TEST(ProductOperator, ProductOfZeroAndInteger)
{
    ASSERT_EQ(RubberInt(0) * RubberInt("134141414133152542635653735"), RubberInt(0));
}

TEST(ProductOperator, ProductOfSmallIntegersOfDifferentSigns)
{
    ASSERT_EQ(RubberInt(-3143) * RubberInt(3242), RubberInt(-3143 * 3242));
}

TEST(ProductOperator, ProductOfBigIntegersOfDifferentSigns)
{
    ASSERT_EQ(RubberInt("19480139740137401192104710") * RubberInt("-23705275729787129138473194"), RubberInt("-461782083794740889215327230235679720207736776143740"));
}

TEST(ProductOperator, ProductOfSmallNegativeIntegers)
{
    ASSERT_EQ(RubberInt(-1934) * RubberInt(-2384), RubberInt(-1934 * -2384));
}

TEST(ProductOperator, ProductOfBigNegativeIntegers)
{
    ASSERT_EQ(RubberInt("-134913044130712341432124") * RubberInt("-983245287948793487934"), RubberInt("132652614924350539374442982838992830673991816"));
}

TEST(DivisionOperator, ExactDivision)
{
    ASSERT_EQ(RubberInt(57) / RubberInt(19), RubberInt(3));
}

TEST(DivisionOperator, DivisionOfZeroByZero)
{
    ASSERT_THROW(RubberInt(0) / RubberInt(0), RubberDivisionByZero);
}

TEST(DivisionOperator, DivisionOfNonZeroByZero)
{
    ASSERT_THROW(RubberInt(1) / RubberInt(0), RubberDivisionByZero);
}

TEST(DivisionOperator, DivisionWithTruncation)
{
    ASSERT_EQ(RubberInt(55) / RubberInt(28), RubberInt(1));
}

TEST(DivisionOperator, DivisionWithNegativeTruncation)
{
    ASSERT_EQ(RubberInt(3) / RubberInt(-2), RubberInt(-1));
}

TEST(DivisionOperator, DivisionOfBigPositiveIntegerByOne)
{
    ASSERT_EQ(RubberInt("7324893749287493274922") / RubberInt("1"), RubberInt("7324893749287493274922"));
}

TEST(DivisionOperator, DivisionOfSmallPositiveIntegers)
{
    ASSERT_EQ(RubberInt(3240) / RubberInt(124), RubberInt(26));
}

TEST(DivisionOperator, DivisionOfBigPositiveIntegers)
{
    ASSERT_EQ(RubberInt("7324893749287493274922") / RubberInt("2304392040194914031134"), RubberInt("3"));
}

TEST(DivisionOperator, DivisionOfZeroAndInteger)
{
    ASSERT_EQ(RubberInt(0) / RubberInt(39140), RubberInt(0));
}

TEST(DivisionOperator, DivisionOfSmallIntegersOfDifferentSigns)
{
    ASSERT_EQ(RubberInt(1342) / RubberInt(-131), RubberInt(1342 / -131));
}

TEST(DivisionOperator, DivisionOfBigIntegersOfDifferentSigns)
{
    ASSERT_EQ(RubberInt("9084328243225215732054") / RubberInt("-9014831849130840138431"), RubberInt("-1"));
}

TEST(DivisionOperator, DivisionOfSmallNegativeIntegers)
{
    ASSERT_EQ(RubberInt(3241) / RubberInt(-1324), RubberInt(3241 / -1324));
}

TEST(DivisionOperator, DivisionOfBigNegativeIntegers)
{
    ASSERT_EQ(RubberInt("-2148310481940142123111") / RubberInt("-1243141342234143141341"), RubberInt("1"));
}

TEST(Abs, AbsoluteValueOfPositiveInteger)
{
    ASSERT_EQ(RubberInt(1243141341).abs(), RubberInt(1243141341));
}

TEST(Abs, AbsoluteValueOfZero)
{
    ASSERT_EQ(RubberInt(0).abs(), RubberInt(0));
}

TEST(Abs, AbsoluteValueOfNegativeInteger)
{
    ASSERT_EQ(RubberInt(-103941).abs(), RubberInt(103941));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}