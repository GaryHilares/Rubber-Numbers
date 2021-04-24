/*******************************************************************************************
 * This file is part of Rubber Integers by GaryNLOL.
 * Special thanks to my family and µ's.
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

namespace RubberIntegers
{
    class RubberInt
    {
    private:
        std::string val;
        bool isNegative;
        static bool isValidInput(const std::string& str);
        void deleteTrailingZeroes();
    public:
        RubberInt();
        RubberInt(const std::string& newVal);
        template<typename IntType, typename = typename std::enable_if<std::is_integral<IntType>::value>::type>
        RubberInt(const IntType newVal)
        {
            *this = RubberInt(std::to_string(newVal));
        }
        bool operator==(const RubberInt& num2) const;
        bool operator!=(const RubberInt& num2) const;
        bool operator>(const RubberInt& num2) const;
        bool operator<=(const RubberInt& num2) const;
        bool operator>=(const RubberInt& num2) const;
        bool operator<(const RubberInt& num2) const;
        RubberInt operator+(const RubberInt& num2) const;
        RubberInt operator-(const RubberInt& num2) const;
        RubberInt operator+=(const RubberInt& num2);
        RubberInt operator-=(const RubberInt& num2);
        RubberInt operator++(int);
        RubberInt operator++();
        RubberInt operator--(int);
        RubberInt operator--();
        RubberInt operator*(const RubberInt& num2) const;
        RubberInt operator*=(const RubberInt& num2);
        RubberInt operator/(const RubberInt& num2) const;
        RubberInt operator/=(const RubberInt& num2);
        RubberInt operator%(const RubberInt& num2) const;
        RubberInt operator%=(const RubberInt& num2);
        RubberInt factorial() const;
        RubberInt abs() const;
        std::string toString() const;
    };
    std::ostream& operator<<(std::ostream& stream, const RubberInt& num);
    std::istream& operator>>(std::istream& stream, RubberInt& num);
}

#ifndef RUBBER_INTEGERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
namespace std
{
    string to_string(const RubberIntegers::RubberInt& num);
}
#endif // RUBBER_INTEGERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
