/*******************************************************************************************
 *
 * This file is part of Rubber Integers by GaryNLOL.
 * Former part of Rubber Integers by GaryNLOL.
 * Special thanks to my family and µ's.
 *
 *******************************************************************************************
 *
 * MIT License
 * Copyright (c) 2020 GaryNLOL
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *******************************************************************************************/


#pragma once
#include <iostream>
#include <string>

namespace RubberNumbers
{
    class RubberInt
    {
    private:
        std::string val;
        bool is_negative;
        /** RubberInt::isValidInput
          *
          * @param A std::string.
          * @return True if the string contains a valid
          *         value to initialize a RubberInt,
          *         false otherwise.
          * @throws Never throws.
          *
          */
        static bool isValidInput(const std::string& str);
        /** RubberInt::deleteTrailingZeroes
          *
          * @throws Never throws.
          *
          */
        void deleteTrailingZeroes();
    public:
        /** RubberInt::RubberInt
          *
          * @return A RubberInt with the value of 0.
          * @throws Never throws.
          *
          */
        RubberInt();
        /** RubberInt::RubberInt
          *
          * @param A std::string with an integer value on it.
          * @return A RubberInt with the given value.
          * @throws Throws std::invalid_argument if the std::string
          *         has a value that is not a valid integer number.
          *
          */
        RubberInt(const std::string& new_val);
        /** RubberInt::RubberInt
          *
          * @param A type of integer point.
          * @return A RubberInt with the given value.
          * @throws Never throws.
          *
          */
        template<typename IntType, typename = typename std::enable_if<std::is_integral<IntType>::value>::type>
        RubberInt(const IntType new_val)
        {
            *this = RubberInt(std::to_string(new_val));
        }
        /** RubberInt::operator==
          *
          * @param A RubberInt to check for equality.
          * @return True if both values are equal, false
          *         otherwise.
          * @throws Never throws.
          *
          */
        bool operator==(const RubberInt& num2) const;
        /** RubberInt::operator!=
          *
          * @param A RubberInt to check for equality.
          * @return True if both values are not equal, false
          *         otherwise.
          * @throws Never throws.
          *
          */
        bool operator!=(const RubberInt& num2) const;
        /** RubberInt::operator>
          *
          * @param A RubberInt to compare.
          * @return True if the value of the first is greater
          *         than the value of the second, false otherwise.
          * @throws Never throws.
          *
          */
        bool operator>(const RubberInt& num2) const;
        /** RubberInt::operator<
          *
          * @param A RubberInt to compare.
          * @return True if the value of the first is less
          *         than the value of the second, false otherwise.
          * @throws Never throws.
          *
          */
        bool operator<(const RubberInt& num2) const;
        /** RubberInt::operator>=
          *
          * @param A RubberInt to compare.
          * @return True if the value of the first is greater
          *         than or equal to the value of the second,
          *         false otherwise.
          * @throws Never throws.
          *
          */
        bool operator>=(const RubberInt& num2) const;
        /** RubberInt::operator<=
          *
          * @param A RubberInt to compare.
          * @return True if the value of the first is less
          *         than or equal to the value of the second,
          *         false otherwise.
          * @throws Never throws.
          *
          */
        bool operator<=(const RubberInt& num2) const;
        /** RubberInt::operator+
          *
          * @param A RubberInt to sum.
          * @return A RubberInt with the sum of the two
          *         RubberInts.
          * @throws Never throws.
          *
          */
        RubberInt operator+(const RubberInt& num2) const;
        /** RubberInt::operator+=
          *
          * @param A RubberInt to sum.
          * @return A RubberInt with the sum of the two
          *         RubberInts.
          * @throws Never throws.
          *
          */
        RubberInt operator+=(const RubberInt& num2);
        /** RubberInt::operator-
          *
          * @param A RubberInt to substract.
          * @return A RubberInt with the substraction of the
          *         two RubberInts.
          * @throws Never throws.
          *
          */
        RubberInt operator-(const RubberInt& num2) const;
        /** RubberInt::operator-=
          *
          * @param A RubberInt to substract.
          * @return A RubberInt with the substraction of the
          *         two RubberInts.
          * @throws Never throws.
          *
          */
        RubberInt operator-=(const RubberInt& num2);
        /** RubberInt::operator++(postfix)
          *
          * @return A RubberInt with the value of this before
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberInt operator++(int);
        /** RubberInt::operator--(postfix)
          *
          * @return A RubberInt with the value of this before
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberInt operator--(int);
        /** RubberInt::operator++(prefix)
          *
          * @return A RubberInt with the value of this after
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberInt operator++();
        /** RubberInt::operator++(prefix)
          *
          * @return A RubberInt with the value of this before
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberInt operator--();
        /** RubberInt::operator*
          *
          * @param A RubberInt to multiply.
          * @return A RubberInt with the product of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberInt operator*(const RubberInt& num2) const;
        /** RubberInt::operator*=
          *
          * @param A RubberInt to multiply.
          * @return A RubberInt with the product of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberInt operator*=(const RubberInt& num2);
        /** RubberInt::operator/
          *
          * @param A RubberInt to divide.
          * @return A RubberInt with the cocient of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberInt operator/(const RubberInt& num2) const;
        /** RubberInt::operator/=
          *
          * @param A RubberInt to divide.
          * @return A RubberInt with the cocient of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberInt operator/=(const RubberInt& num2);
        /** RubberInt::operator%
          *
          * @param A RubberInt to divide.
          * @return A RubberInt with the residue of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberInt operator%(const RubberInt& num2) const;
        /** RubberInt::operator%=
          *
          * @param A RubberInt to divide.
          * @return A RubberInt with the residue of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberInt operator%=(const RubberInt& num2);
        /** RubberInt::factorial
          *
          * @return A RubberInt with the factorial of
          *         this.
          * @throws Never throws.
          *
          */
        RubberInt factorial() const;
        /** RubberInt::abs
          *
          * @return A RubberInt with the absolute value
          *         of this.
          * @throws Never throws.
          *
          */
        RubberInt abs() const;
        /** RubberInt::toString
          *
          * @return A std::string with the value of this.
          * @throws Never throws.
          *
          */
        std::string toString() const;
        /** RubberInt::toLongLong
          *
          * @return The value of this.
          * @throws Throw std::invalid_argument if this is
          *         greater than LONG_LONG_MAX.
          *
          */
        long long toLongLong() const;
        /** RubberInt::toUnsignedLongLong
          *
          * @return The value of this.
          * @throws Throw std::invalid_argument if this is
          *         greater than ULONG_LONG_MAX.
          *
          */
        unsigned long long toUnsignedLongLong() const;
    };
    /** operator<<
      *
      * @param A reference to a std::ostream.
      * @param A RubberInt to stream.
      * @return A reference to the std::ostream
      *         after the operation.
      * @throws Never throws.
      *
      */
    std::ostream& operator<<(std::ostream& stream, const RubberInt& num);
    /** operator>>
      *
      * @param A reference to a std::istream.
      * @param A RubberInt to save the reading of the stream.
      * @return A reference to the std::istream
      *         after the operation.
      * @throws Never throws.
      *
      */
    std::istream& operator>>(std::istream& stream, RubberInt& num);
}

#ifndef RUBBER_NUMBERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
namespace std
{
    /** std::to_string()
      *
      * @param A RubberInt to convert to string.
      * @return A std::string with the value of the
      *         RubberInt.
      * @throws Never throws.
      *
      */
    string to_string(const RubberNumbers::RubberInt& num);
}
#endif // RUBBER_INTEGERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
