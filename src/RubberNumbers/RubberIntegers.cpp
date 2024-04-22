#include "../../include/RubberNumbers/RubberIntegers.hpp"
#include <climits>
#include <vector>

bool RubberNumbers::RubberInt::isValidInput(const std::string& str)
{
    if (str.size() == 0 || str == "-")
        return false;
    for (std::string::size_type i = (str[0] == '-'); i < str.size(); i++)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

void RubberNumbers::RubberInt::deleteTrailingZeroes()
{
    for (unsigned int i = 0; i < this->val.size(); i++) {
        if (this->val[i] != '0' || i == this->val.size() - 1) {
            this->val.erase(0, i);
            break;
        }
    }
}

RubberNumbers::RubberInt::RubberInt()
{
    this->is_negative = false;
    this->val = "0";
}

RubberNumbers::RubberInt::RubberInt(const std::string& new_val)
{
    if (!isValidInput(new_val))
        throw std::invalid_argument("RubberInt::RubberInt(" + new_val + ")");
    this->is_negative = (new_val[0] == '-');
    this->val = new_val.substr(is_negative, new_val.size() - is_negative);
    this->deleteTrailingZeroes();
}

std::string RubberNumbers::RubberInt::toString() const
{
    return this->is_negative ? ("-" + this->val) : (this->val);
}

std::ostream& RubberNumbers::operator<<(std::ostream& stream, const RubberInt& num)
{
    stream << num.toString();
    return stream;
}

std::istream& RubberNumbers::operator>>(std::istream& stream, RubberInt& num)
{
    std::string check_str;
    stream >> check_str;
    num = RubberInt(check_str);
    return stream;
}

bool RubberNumbers::RubberInt::operator==(const RubberInt& num2) const
{
    return (this->is_negative == num2.is_negative) && (this->val == num2.val);
}

bool RubberNumbers::RubberInt::operator!=(const RubberInt& num2) const
{
    return !(*this == num2);
}

bool RubberNumbers::RubberInt::operator>(const RubberInt& num2) const
{
    if (this->is_negative && !num2.is_negative) {
        return false;
    }
    if (!this->is_negative && num2.is_negative) {
        return true;
    }
    if (!this->is_negative && !num2.is_negative) {
        if (this->val.size() > num2.val.size()) {
            return true;
        }
        if (this->val.size() < num2.val.size()) {
            return false;
        }
        if (this->val.size() == num2.val.size()) {
            for (std::string::size_type i = 0; i < this->val.size(); i++) {
                if (this->val[i] > num2.val[i])
                    return true;
                if (this->val[i] < num2.val[i])
                    return false;
            }
            return false;
        }
    }
    if (this->is_negative && num2.is_negative) {
        if (this->val.size() > num2.val.size()) {
            return false;
        }
        if (this->val.size() < num2.val.size()) {
            return true;
        }
        if (this->val.size() == num2.val.size()) {
            for (std::string::size_type i = 0; i < this->val.size(); i++) {
                if (this->val[i] > num2.val[i])
                    return false;
                if (this->val[i] < num2.val[i])
                    return true;
            }
            return false;
        }
    }
    throw std::invalid_argument("RubberInt::operator>(Not possible case)");
}
bool RubberNumbers::RubberInt::operator<=(const RubberInt& num2) const
{
    return *this == num2 || *this < num2;
}
bool RubberNumbers::RubberInt::operator>=(const RubberInt& num2) const
{
    return *this == num2 || *this > num2;
}
bool RubberNumbers::RubberInt::operator<(const RubberInt& num2) const
{
    return !(*this == num2 || *this > num2);
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator+(const RubberInt& num2) const
{
    if (this->is_negative == num2.is_negative) {
        std::string answer;
        int carry = 0;
        for (int i = this->val.size() - 1, j = num2.val.size() - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int operand1 = (i >= 0) ? (this->val[i] - '0') : (0);
            int operand2 = (j >= 0) ? (num2.val[j] - '0') : (0);
            int result = operand1 + operand2 + carry;
            if (result >= 10) {
                carry = 1;
                result -= 10;
            } else {
                carry = 0;
            }
            answer += char(result + '0');
        }
        answer = std::string(answer.rbegin(), answer.rend());
        return RubberInt(this->is_negative ? ("-" + answer) : (answer));
    } else {
        const RubberInt& positive = this->is_negative ? num2.val : this->val;
        const RubberInt& negative = this->is_negative ? this->val : num2.val;
        if (positive == negative)
            return RubberInt(0);
        std::string answer;
        int carry = 0;
        bool result_is_negative = negative > positive;
        for (int i = positive.val.size() - 1, j = negative.val.size() - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int operand1 = (i >= 0) ? (positive.val[i] - '0') : 0;
            int operand2 = (j >= 0) ? (negative.val[j] - '0') : 0;
            int result;
            if (result_is_negative)
                result = operand2 - (operand1 + carry);
            else
                result = operand1 - (operand2 + carry);
            if (0 > result) {
                carry = 1;
                result += 10;
            } else {
                carry = 0;
            }
            answer += char(result + '0');
        }
        answer = (result_is_negative ? "-" : "") + std::string(answer.rbegin(), answer.rend());
        return RubberInt(answer);
    }
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator-(const RubberInt& num2) const
{
    RubberInt inverted_sign_num2(num2);
    inverted_sign_num2.is_negative = !inverted_sign_num2.is_negative;
    return *this + inverted_sign_num2;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator+=(const RubberInt& num2)
{
    *this = *this + num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator-=(const RubberInt& num2)
{
    *this = *this - num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator++(int)
{
    RubberInt ret = *this;
    *this = *this + RubberInt(1);
    return ret;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator++()
{
    *this = *this + 1;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator--(int)
{
    RubberInt ret = *this;
    *this = *this - RubberInt(1);
    return ret;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator--()
{
    *this = *this - RubberInt(1);
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator*(const RubberInt& num2) const
{
    if (this->val == "0" || num2.val == "0")
        return RubberInt(0);
    std::vector<RubberInt> unitary_results;
    for (int i = this->val.size() - 1; i >= 0; i--) {
        std::string unitary_answer;
        int carry = 0;
        int operand1 = this->val[i] - '0';
        for (int j = num2.val.size() - 1; j >= 0 || carry != 0; j--) {
            int operand2 = (j >= 0) ? (num2.val[j] - '0') : (0);
            int result = operand1 * operand2 + carry;
            carry = result / 10;
            result %= 10;
            unitary_answer += char(result + 48);
        }
        unitary_answer = std::string(unitary_answer.rbegin(), unitary_answer.rend()) + std::string(unitary_results.size(), '0');
        unitary_results.push_back(RubberInt(unitary_answer));
    }
    RubberInt answer;
    for (unsigned int i = 0; i < unitary_results.size(); i++)
        answer += unitary_results[i];
    answer.is_negative = (this->is_negative != num2.is_negative);
    return answer;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator*=(const RubberInt& num2)
{
    *this = *this * num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator/(const RubberInt& num2) const
{
    const RubberInt dividend = this->abs();
    const RubberInt divisor = num2.abs();
    RubberInt remainder;
    remainder.val = "";
    std::string cocient;
    unsigned int current_index = 0;
    while (current_index < dividend.val.size()) {
        if (current_index < dividend.val.size()) {
            remainder.val += dividend.val[current_index];
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
    return RubberInt(cocient);
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator/=(const RubberInt& num2)
{
    *this = *this / num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator%(const RubberInt& num2) const
{
    const RubberInt dividend = this->abs();
    const RubberInt divisor = num2.abs();
    RubberInt remainder;
    remainder.val = "";
    std::string cocient;
    unsigned int currentIndex = 0;
    while (currentIndex < dividend.val.size()) {
        if (currentIndex < dividend.val.size()) {
            remainder.val += dividend.val[currentIndex];
            currentIndex++;
        }
        if (remainder >= divisor) {
            unsigned int counter = 0;
            while (remainder >= divisor) {
                remainder -= divisor;
                counter++;
            }
        }
    }
    return remainder;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator%=(const RubberInt& num2)
{
    *this = *this % num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::factorial() const
{
    if (this->is_negative)
        throw std::invalid_argument("RubberInt::factorial(" + this->val + ")");
    RubberInt result = 1;
    for (RubberInt i = this->val; i > 0; i--) {
        result *= i;
    }
    return result;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::abs() const
{
    if (!this->is_negative)
        return *this;
    return RubberInt(this->val);
}

std::string std::to_string(const RubberNumbers::RubberInt& num)
{
    return num.toString();
}

long long RubberNumbers::RubberInt::toLongLong() const
{
    if (*this > RubberInt(LONG_LONG_MAX))
        throw std::invalid_argument("RubberInt::toLongLong(" + this->toString() + ")");
    return std::strtoll(((this->is_negative ? "-" : "") + this->val).c_str(), nullptr, 10);
}

unsigned long long RubberNumbers::RubberInt::toUnsignedLongLong() const
{
    if (*this > RubberInt(ULONG_LONG_MAX))
        throw std::invalid_argument("RubberInt::toUnsignedLongLong(" + this->toString() + ")");
    return std::strtoull(((this->is_negative ? "-" : "") + this->val).c_str(), nullptr, 10);
}
