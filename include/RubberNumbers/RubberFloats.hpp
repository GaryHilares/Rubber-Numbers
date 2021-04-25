/*******************************************************************************************
 *
 * This file is part of Rubber Floats by GaryNLOL.
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
        static bool isValidInput(const std::string& str);
        void deleteTrailingZeroes();
    public:
        RubberFloat();
        RubberFloat(const std::string& new_val);
        template<typename float_type, typename = typename std::enable_if<std::is_floating_point<float_type>::value || std::is_integral<float_type>::value>::type>
        RubberFloat(const float_type new_val)
        {
            *this = RubberFloat(std::to_string(new_val));
        }
        std::string to_string() const;
        bool operator==(const RubberFloat& num2) const;
        bool operator!=(const RubberFloat& num2) const;
        bool operator>(const RubberFloat& num2) const;
        bool operator<(const RubberFloat& num2) const;
        bool operator>=(const RubberFloat& num2) const;
        bool operator<=(const RubberFloat& num2) const;
        RubberFloat operator+(const RubberFloat& num2) const;
        RubberFloat operator +=(const RubberFloat& num2);
        RubberFloat operator-(const RubberFloat& num2) const;
        RubberFloat operator -=(const RubberFloat& num2);
        RubberFloat operator++(int);
        RubberFloat operator--(int);
        RubberFloat operator++();
        RubberFloat operator--();
        RubberFloat operator*(const RubberFloat& num2) const;
        RubberFloat operator*=(const RubberFloat& num2);
        RubberFloat operator/(const RubberFloat& num2) const;
        RubberFloat operator/=(const RubberFloat& num2);
        RubberFloat operator%(const RubberFloat& num2) const;
        RubberFloat operator%=(const RubberFloat& num2);
        RubberFloat abs() const;
        static unsigned int setPrecision(unsigned int new_precision);
        static unsigned int getPrecision();
    };
    std::istream& operator>>(std::istream& stream, RubberFloat& num);
    std::ostream& operator<<(std::ostream& stream, const RubberFloat& num);
}

#ifndef RUBBER_NUMBERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
namespace std
{
    string to_string(const RubberNumbers::RubberFloat& num);
}
#endif // RUBBER_INTEGERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
