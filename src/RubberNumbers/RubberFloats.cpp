#include "../../include/RubberNumbers/RubberFloats.hpp"
#include <cmath>
#include <vector>

bool RubberNumbers::RubberFloat::isValidInput(const std::string& str)
{
    if (str.size() == 0 || str == "-" || str == "." || str == "-.")
        return false;
    bool did_point_appear = false;
    for (unsigned int i = (str[0] == '-'); i < str.size(); i++) {
        if (!std::isdigit(str[i])) {
            if (str[i] == '.' && !did_point_appear)
                did_point_appear = true;
            else
                return false;
        }
    }
    return true;
}

void RubberNumbers::RubberFloat::deleteTrailingZeroes()
{
    for (std::string::size_type i = 0; i < this->integral_val.size(); i++) {
        if (i == this->integral_val.size() - 1 || this->integral_val[i] != '0') {
            this->integral_val.erase(0, i);
            break;
        }
    }
    for (std::string::size_type i = this->decimal_val.size() - 1; true /*(i >= 0)*/; i--) {
        if (i == 0 || this->decimal_val[i] != '0') {
            this->decimal_val.erase(i + 1, this->decimal_val.size() - i - 1);
            break;
        }
    }
}

RubberNumbers::RubberFloat::RubberFloat()
{
    this->is_negative = false;
    this->integral_val = "0";
    this->decimal_val = "0";
}

RubberNumbers::RubberFloat::RubberFloat(const std::string& new_val)
{
    if (!isValidInput(new_val))
        throw std::invalid_argument("RubberFloat::RubberFloat(" + new_val + ")");
    this->is_negative = (new_val[0] == '-');
    std::string ::size_type point_index = new_val.find('.');
    if (point_index == new_val.npos || point_index == new_val.size() - 1) {
        this->integral_val = new_val.substr(this->is_negative, new_val.size() - this->is_negative - (point_index == new_val.size() - 1));
        this->decimal_val = "0";
    } else if (point_index == this->is_negative) {
        this->integral_val = "0";
        this->decimal_val = new_val.substr(this->is_negative + 1, new_val.size() - this->is_negative - 1);
    } else {
        this->integral_val = new_val.substr(this->is_negative, point_index - this->is_negative);
        this->decimal_val = new_val.substr(point_index + 1, new_val.size() - point_index - 1);
    }
    this->deleteTrailingZeroes();
}

std::string RubberNumbers::RubberFloat::toString() const
{
    return (is_negative ? "-" : "") + integral_val + "." + decimal_val;
}

std::ostream& RubberNumbers::operator<<(std::ostream& stream, const RubberFloat& num)
{
    stream << num.toString();
    return stream;
}

std::istream& RubberNumbers::operator>>(std::istream& stream, RubberFloat& num)
{
    std::string check_str;
    stream >> check_str;
    num = RubberFloat(check_str);
    return stream;
}

bool RubberNumbers::RubberFloat::operator==(const RubberFloat& num2) const
{
    return this->is_negative == num2.is_negative && this->integral_val == num2.integral_val && this->decimal_val == num2.decimal_val;
}

bool RubberNumbers::RubberFloat::operator!=(const RubberFloat& num2) const
{
    return !(*this == num2);
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::abs() const
{
    RubberFloat ret = *this;
    ret.is_negative = false;
    return ret;
}

bool RubberNumbers::RubberFloat::operator>(const RubberFloat& num2) const
{
    if (this->is_negative != num2.is_negative)
        return !this->is_negative;
    if (*this == num2)
        return false;
    if (this->is_negative)
        return this->abs() < num2.abs();
    if (this->integral_val.size() != num2.integral_val.size())
        return this->integral_val.size() > num2.integral_val.size();
    for (std::string::size_type i = 0; i < this->integral_val.size(); i++) {
        if (this->integral_val[i] > num2.integral_val[i])
            return true;
        else if (this->integral_val[i] < num2.integral_val[i])
            return false;
    }
    if (this->decimal_val.size() != num2.decimal_val.size())
        return this->decimal_val.size() > num2.decimal_val.size();
    for (std::string::size_type i = 0; i < this->decimal_val.size(); i++) {
        if (this->decimal_val[i] > num2.decimal_val[i])
            return true;
        else if (this->decimal_val[i] < num2.decimal_val[i])
            return false;
    }
    throw std::invalid_argument("RubberFloat::operator>(Impossible result)");
}

bool RubberNumbers::RubberFloat::operator<(const RubberFloat& num2) const
{
    return !((*this > num2) || (*this == num2));
}

bool RubberNumbers::RubberFloat::operator>=(const RubberFloat& num2) const
{
    return (*this == num2) || (*this > num2);
}

bool RubberNumbers::RubberFloat::operator<=(const RubberFloat& num2) const
{
    return (*this == num2) || (*this < num2);
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator+(const RubberFloat& num2) const
{
    if (this->is_negative == num2.is_negative) {
        std::string answer;
        int carry = 0;
        for (std::string::size_type i = std::max(this->decimal_val.size() - 1, num2.decimal_val.size() - 1); true /*Check break at the end of the block*/; i--) {
            int operand1 = (i < this->decimal_val.size()) ? (this->decimal_val[i] - '0') : (0);
            int operand2 = (i < num2.decimal_val.size()) ? (num2.decimal_val[i] - '0') : (0);
            int result = operand1 + operand2 + carry;
            if (result >= 10) {
                result -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            answer += char(result + '0');
            if (i == 0)
                break;
        }
        answer += ".";
        for (int i = this->integral_val.size() - 1, j = num2.integral_val.size() - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int operand1 = (i >= 0) ? (this->integral_val[i] - '0') : 0;
            int operand2 = (j >= 0) ? (num2.integral_val[j] - '0') : 0;
            int result = operand1 + operand2 + carry;
            if (result >= 10) {
                result -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            answer += char(result + '0');
        }
        answer = (this->is_negative ? "-" : "") + std::string(answer.rbegin(), answer.rend());
        return RubberFloat(answer);
    } else {
        if (this->abs() == num2.abs())
            return RubberFloat(0);
        const RubberFloat& positive = this->is_negative ? num2.abs() : this->abs();
        const RubberFloat& negative = this->is_negative ? this->abs() : num2.abs();
        bool is_result_negative = negative > positive;
        std::string answer;
        int carry = 0;
        for (std::string::size_type i = std::max(positive.decimal_val.size() - 1, negative.decimal_val.size() - 1); true /*Check break at the end of the block*/; i--) {
            int operand1 = (i < positive.decimal_val.size()) ? (positive.decimal_val[i] - '0') : (0);
            int operand2 = (i < negative.decimal_val.size()) ? (negative.decimal_val[i] - '0') : (0);
            int result;
            if (is_result_negative)
                result = operand2 - (operand1 + carry);
            else
                result = operand1 - (operand2 + carry);
            if (result < 0) {
                result += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            answer += char(result + '0');
            if (i == 0)
                break;
        }
        answer += ".";
        for (int i = positive.integral_val.size() - 1, j = negative.integral_val.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int operand1 = (i >= 0) ? (positive.integral_val[i] - '0') : 0;
            int operand2 = (j >= 0) ? (negative.integral_val[j] - '0') : 0;
            int result;
            if (is_result_negative)
                result = operand2 - (operand1 + carry);
            else
                result = operand1 - (operand2 + carry);
            if (result < 0) {
                result += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            answer += char(result + '0');
        }
        answer = (is_result_negative ? "-" : "") + std::string(answer.rbegin(), answer.rend());
        return RubberFloat(answer);
    }
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator+=(const RubberFloat& num2)
{
    *this = *this + num2;
    return *this;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator-(const RubberFloat& num2) const
{
    RubberFloat tmp = num2;
    tmp.is_negative = !tmp.is_negative;
    return *this + tmp;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator-=(const RubberFloat& num2)
{
    *this = *this - num2;
    return *this;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator++(int)
{
    RubberFloat tmp = *this;
    *this += RubberFloat(1);
    return tmp;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator--(int)
{
    RubberFloat tmp = *this;
    *this -= RubberFloat(1);
    return tmp;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator++()
{
    *this += RubberFloat(1);
    return *this;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator--()
{
    *this -= 1;
    return *this;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator*(const RubberFloat& num2) const
{
    if ((this->integral_val == "0" && this->decimal_val == "0") || (num2.integral_val == "0" && num2.decimal_val == "0"))
        return RubberFloat(0);
    std::vector<RubberFloat> unitary_results;
    const std::string num1_val = this->integral_val + this->decimal_val;
    const std::string num2_val = num2.integral_val + num2.decimal_val;
    for (int i = num1_val.size() - 1; i >= 0; i--) {
        std::string unitary_answer;
        int carry = 0;
        int operand1 = num1_val[i] - '0';
        for (int j = num2_val.size() - 1; j >= 0 || carry != 0; j--) {
            int operand2 = (j >= 0) ? (num2_val[j] - '0') : (0);
            int result = operand1 * operand2 + carry;
            carry = result / 10;
            result %= 10;
            unitary_answer += char(result + 48);
        }
        unitary_answer = std::string(unitary_answer.rbegin(), unitary_answer.rend()) + std::string(unitary_results.size(), '0');
        unitary_results.push_back(RubberFloat(unitary_answer));
    }
    RubberFloat answer;
    for (unsigned int i = 0; i < unitary_results.size(); i++)
        answer += unitary_results[i];
    answer.decimal_val = answer.integral_val.substr(answer.integral_val.size() - (this->decimal_val.size() + num2.decimal_val.size()), this->decimal_val.size() + num2.decimal_val.size());
    answer.integral_val = answer.integral_val.substr(0, answer.integral_val.size() - (this->decimal_val.size() + num2.decimal_val.size()));
    answer.is_negative = (this->is_negative != num2.is_negative);
    answer.deleteTrailingZeroes();
    return answer;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator*=(const RubberFloat& num2)
{
    *this = *this * num2;
    return *this;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator/(const RubberFloat& num2) const
{
    unsigned int maxDecimalsNow = std::max(this->decimal_val.size(), num2.decimal_val.size()) - (this->decimal_val == "0" && num2.decimal_val == "0");
    const RubberFloat dividend = (this->abs() * pow(10, maxDecimalsNow));
    const RubberFloat divisor = (num2.abs() * pow(10, maxDecimalsNow));
    RubberFloat remainder;
    remainder.integral_val = "";
    std::string cocient;
    unsigned int precision = getPrecision();
    unsigned int current_index = 0;
    bool point = false;
    while ((cocient.find('.') == cocient.npos || cocient.size() - cocient.find('.') < precision) && !(remainder == 0 && current_index >= dividend.integral_val.size())) {
        if (current_index >= dividend.integral_val.size()) {
            if (!point) {
                cocient += '.';
                point = true;
            }
            remainder.integral_val += '0';
        } else {
            remainder.integral_val += dividend.integral_val[current_index];
            current_index++;
        }
        if (divisor > remainder) {
            cocient += "0";
        } else {
            unsigned int counter = 0;
            while (remainder >= divisor) {
                remainder -= divisor;
                counter++;
            }
            cocient += char(counter + '0');
        }
    }
    cocient = (this->is_negative == num2.is_negative ? "" : "-") + cocient;
    return RubberFloat(cocient);
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator/=(const RubberFloat& num2)
{
    *this = *this / num2;
    return *this;
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator%(const RubberFloat& num2) const
{
    unsigned int max_decimals_now = std::max(this->decimal_val.size(), num2.decimal_val.size()) - (this->decimal_val == "0" && num2.decimal_val == "0");
    const RubberFloat dividend = (this->abs() * RubberFloat(pow(10, max_decimals_now)));
    const RubberFloat divisor = (num2.abs() * RubberFloat(pow(10, max_decimals_now)));
    RubberFloat remainder;
    remainder.integral_val = "";
    std::string cocient;
    unsigned int current_index = 0;
    while (!(remainder == 0 && current_index >= dividend.integral_val.size())) {
        if (current_index >= dividend.integral_val.size()) {
            remainder.deleteTrailingZeroes();
            return remainder / RubberFloat(pow(10, max_decimals_now));
        } else {
            remainder.integral_val += dividend.integral_val[current_index];
            current_index++;
        }
        while (divisor <= remainder) {
            remainder -= divisor;
        }
    }
    return RubberFloat(0);
}

RubberNumbers::RubberFloat RubberNumbers::RubberFloat::operator%=(const RubberFloat& num2)
{
    *this = *this % num2;
    return *this;
}

unsigned int RubberNumbers::RubberFloat::setPrecision(unsigned int new_precision)
{
    static unsigned int precision = 10;
    if (new_precision == 0) {
        return precision;
    } else {
        precision = new_precision;
        return 0;
    }
}

unsigned int RubberNumbers::RubberFloat::getPrecision()
{
    return setPrecision(0);
}

std::string std::to_string(const RubberNumbers::RubberFloat& num)
{
    return num.toString();
}
