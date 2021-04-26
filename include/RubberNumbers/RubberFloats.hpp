/*******************************************************************************************
 *
 * This file is part of Rubber Numbers by GaryNLOL.
 * Former part of Rubber Floats by GaryNLOL.
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
    class RubberFloat
    {
    private:
        bool is_negative;
        std::string integral_val;
        std::string decimal_val;
        /** RubberFloat::isValidInput
          *
          * @param A std::string.
          * @return True if the string contains a valid
          *         value to initialize a RubberFloat,
          *         false otherwise.
          * @throws Never throws.
          *
          */
        static bool isValidInput(const std::string& str);
        /** RubberFloat::deleteTrailingZeroes
          *
          * @throws Never throws.
          *
          */
        void deleteTrailingZeroes();
    public:
        /** RubberFloat::RubberFloat
          *
          * @return A RubberFloat with a value of 0.
          * @throws Never throws.
          *
          */
        RubberFloat();
        /** RubberFloat::RubberFloat
          *
          * @param A std::string with a real value on it.
          * @return A RubberFloat with the given value.
          * @throws Throws std::invalid_argument if the std::string
          *         has a value that is not a valid real number.
          *
          */
        RubberFloat(const std::string& new_val);
        /** RubberFloat::RubberFloat
          *
          * @param A type of floating point.
          * @return A RubberFloat with the given value.
          * @throws Never throws.
          *
          */
        template<typename FloatType, typename = typename std::enable_if<std::is_floating_point<FloatType>::value || std::is_integral<FloatType>::value>::type>
        RubberFloat(const FloatType new_val)
        {
            *this = RubberFloat(std::to_string(new_val));
        }
        /** RubberFloat::operator==
          *
          * @param A RubberFloat to check for equality.
          * @return True if both values are equal, false
          *         otherwise.
          * @throws Never throws.
          *
          */
        bool operator==(const RubberFloat& num2) const;
        /** RubberFloat::operator!=
          *
          * @param A RubberFloat to check for equality.
          * @return True if both values are not equal, false
          *         otherwise.
          * @throws Never throws.
          *
          */
        bool operator!=(const RubberFloat& num2) const;
        /** RubberFloat::operator>
          *
          * @param A RubberFloat to compare.
          * @return True if the value of the first is greater
          *         than the value of the second, false otherwise.
          * @throws Never throws.
          *
          */
        bool operator>(const RubberFloat& num2) const;
        /** RubberFloat::operator<
          *
          * @param A RubberFloat to compare.
          * @return True if the value of the first is less
          *         than the value of the second, false otherwise.
          * @throws Never throws.
          *
          */
        bool operator<(const RubberFloat& num2) const;
        /** RubberFloat::operator>=
          *
          * @param A RubberFloat to compare.
          * @return True if the value of the first is greater
          *         than or equal to the value of the second,
          *         false otherwise.
          * @throws Never throws.
          *
          */
        bool operator>=(const RubberFloat& num2) const;
        /** RubberFloat::operator<=
          *
          * @param A RubberFloat to compare.
          * @return True if the value of the first is less
          *         than or equal to the value of the second,
          *         false otherwise.
          * @throws Never throws.
          *
          */
        bool operator<=(const RubberFloat& num2) const;
        /** RubberFloat::operator+
          *
          * @param A RubberFloat to sum.
          * @return A RubberFloat with the sum of the two
          *         RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator+(const RubberFloat& num2) const;
        /** RubberFloat::operator+=
          *
          * @param A RubberFloat to sum.
          * @return A RubberFloat with the sum of the two
          *         RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator +=(const RubberFloat& num2);
        /** RubberFloat::operator-
          *
          * @param A RubberFloat to substract.
          * @return A RubberFloat with the substraction of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator-(const RubberFloat& num2) const;
        /** RubberFloat::operator-=
          *
          * @param A RubberFloat to substract.
          * @return A RubberFloat with the substraction of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator -=(const RubberFloat& num2);
        /** RubberFloat::operator++(postfix)
          *
          * @return A RubberFloat with the value of this before
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberFloat operator++(int);
        /** RubberFloat::operator--(postfix)
          *
          * @return A RubberFloat with the value of this before
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberFloat operator--(int);
        /** RubberFloat::operator++(prefix)
          *
          * @return A RubberFloat with the value of this after
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberFloat operator++();
        /** RubberFloat::operator--(postfix)
          *
          * @return A RubberFloat with the value of this before
          *         the operation.
          * @throws Never throws.
          *
          */
        RubberFloat operator--();
        /** RubberFloat::operator*
          *
          * @param A RubberFloat to multiply.
          * @return A RubberFloat with the product of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator*(const RubberFloat& num2) const;
        /** RubberFloat::operator *=
          *
          * @param A RubberFloat to multiply.
          * @return A RubberFloat with the product of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator*=(const RubberFloat& num2);
        /** RubberFloat::operator/
          *
          * @param A RubberFloat to divide.
          * @return A RubberFloat with the cocient of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator/(const RubberFloat& num2) const;
        /** RubberFloat::operator/=
          *
          * @param A RubberFloat to divide.
          * @return A RubberFloat with the cocient of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator/=(const RubberFloat& num2);
        /** RubberFloat::operator%
          *
          * @param A RubberFloat to divide.
          * @return A RubberFloat with the residue of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator%(const RubberFloat& num2) const;
        /** RubberFloat::operator%=
          *
          * @param A RubberFloat to divide.
          * @return A RubberFloat with the residue of the
          *         two RubberFloats.
          * @throws Never throws.
          *
          */
        RubberFloat operator%=(const RubberFloat& num2);
        /** RubberFloat::abs
          *
          * @return A RubberFloat with the absolute value
          *         of this.
          * @throws Never throws.
          *
          */
        RubberFloat abs() const;
        /** RubberFloat::toString
          *
          * @return A std::string with the value of this.
          * @throws Never throws.
          *
          */
        std::string toString() const;
        /** RubberFloat::getPrecision
          *
          * @param The value to set the precision or 0 to
          *        just get it.
          * @return The precision if the parameter is 0,
          *         0 otherwise.
          * @throws Never throws.
          *
          */
        static unsigned int setPrecision(unsigned int new_precision);
        /** RubberFloat::getPrecision
          *
          * @return The value of the current precision.
          * @throws Never throws.
          *
          */
        static unsigned int getPrecision();
    };
    /** operator>>
      *
      * @param A reference to a std::istream.
      * @param A RubberFloat to save the reading of the stream.
      * @return A reference to the std::istream
      *         after the operation.
      * @throws Never throws.
      *
      */
    std::istream& operator>>(std::istream& stream, RubberFloat& num);
    /** operator<<
      *
      * @param A reference to a std::ostream.
      * @param A RubberFloat to stream.
      * @return A reference to the std::ostream
      *         after the operation.
      * @throws Never throws.
      *
      */
    std::ostream& operator<<(std::ostream& stream, const RubberFloat& num);
}

#ifndef RUBBER_NUMBERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
namespace std
{
    /** std::to_string()
      *
      * @param A RubberFloat to convert to string.
      * @return A std::string with the value of the
      *         RubberFloat.
      * @throws Never throws.
      *
      */
    string to_string(const RubberNumbers::RubberFloat& num);
}
#endif // RUBBER_INTEGERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
