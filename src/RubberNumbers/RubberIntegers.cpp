#include "../../include/RubberNumbers/RubberIntegers.hpp"
#include <climits>
#include <vector>

RubberNumbers::RubberDivisionByZero::RubberDivisionByZero()
    : std::runtime_error("Attempted to divide by zero.")
{
}

bool RubberNumbers::RubberInt::isValidInput(const std::string& str)
{
    if (str.size() == 0 || str == "-") {
        return false;
    }
    for (std::string::size_type i = (str[0] == '-'); i < str.size(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void RubberNumbers::RubberInt::deleteTrailingZeroes()
{
    for (unsigned int i = 0; i < m_value.size(); i++) {
        if (m_value[i] != '0' || i == m_value.size() - 1) {
            m_value.erase(0, i);
            break;
        }
    }
}

RubberNumbers::RubberInt::RubberInt()
{
    m_isNegative = false;
    m_value = "0";
}

RubberNumbers::RubberInt::RubberInt(const std::string& value)
{
    if (!isValidInput(value)) {
        throw std::invalid_argument("RubberInt::RubberInt(" + value + ")");
    }
    m_isNegative = (value[0] == '-');
    m_value = value.substr(m_isNegative, value.size() - m_isNegative);
    this->deleteTrailingZeroes();
}

std::string RubberNumbers::RubberInt::toString() const
{
    return m_isNegative ? ("-" + m_value) : (m_value);
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
    return (m_isNegative == num2.m_isNegative) && (m_value == num2.m_value);
}

bool RubberNumbers::RubberInt::operator!=(const RubberInt& num2) const
{
    return !(*this == num2);
}

bool RubberNumbers::RubberInt::operator>(const RubberInt& num2) const
{
    if (m_isNegative && !num2.m_isNegative) {
        return false;
    }
    if (!m_isNegative && num2.m_isNegative) {
        return true;
    }
    if (!m_isNegative && !num2.m_isNegative) {
        if (m_value.size() > num2.m_value.size()) {
            return true;
        }
        if (m_value.size() < num2.m_value.size()) {
            return false;
        }
        if (m_value.size() == num2.m_value.size()) {
            for (std::string::size_type i = 0; i < m_value.size(); i++) {
                if (m_value[i] > num2.m_value[i]) {
                    return true;
                }
                if (m_value[i] < num2.m_value[i]) {
                    return false;
                }
            }
            return false;
        }
    }
    if (m_isNegative && num2.m_isNegative) {
        if (m_value.size() > num2.m_value.size()) {
            return false;
        }
        if (m_value.size() < num2.m_value.size()) {
            return true;
        }
        if (m_value.size() == num2.m_value.size()) {
            for (std::string::size_type i = 0; i < m_value.size(); i++) {
                if (m_value[i] > num2.m_value[i]) {
                    return false;
                }
                if (m_value[i] < num2.m_value[i]) {
                    return true;
                }
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
    if (m_isNegative == num2.m_isNegative) {
        std::string answer;
        int carry = 0;
        for (int i = m_value.size() - 1, j = num2.m_value.size() - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int operand1 = (i >= 0) ? (m_value[i] - '0') : (0);
            int operand2 = (j >= 0) ? (num2.m_value[j] - '0') : (0);
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
        return RubberInt(m_isNegative ? ("-" + answer) : (answer));
    } else {
        const RubberInt& positive = m_isNegative ? num2.m_value : m_value;
        const RubberInt& negative = m_isNegative ? m_value : num2.m_value;
        if (positive == negative) {
            return RubberInt(0);
        }
        std::string answer;
        int carry = 0;
        bool result_is_negative = negative > positive;
        for (int i = positive.m_value.size() - 1, j = negative.m_value.size() - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int operand1 = (i >= 0) ? (positive.m_value[i] - '0') : 0;
            int operand2 = (j >= 0) ? (negative.m_value[j] - '0') : 0;
            int result;
            if (result_is_negative) {
                result = operand2 - (operand1 + carry);
            } else {
                result = operand1 - (operand2 + carry);
            }
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
    inverted_sign_num2.m_isNegative = !inverted_sign_num2.m_isNegative;
    return *this + inverted_sign_num2;
}

RubberNumbers::RubberInt& RubberNumbers::RubberInt::operator+=(const RubberInt& num2)
{
    *this = *this + num2;
    return *this;
}

RubberNumbers::RubberInt& RubberNumbers::RubberInt::operator-=(const RubberInt& num2)
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

RubberNumbers::RubberInt& RubberNumbers::RubberInt::operator++()
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

RubberNumbers::RubberInt& RubberNumbers::RubberInt::operator--()
{
    *this = *this - RubberInt(1);
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator*(const RubberInt& num2) const
{
    if (m_value == "0" || num2.m_value == "0") {
        return RubberInt(0);
    }
    std::vector<RubberInt> unitary_results;
    for (int i = m_value.size() - 1; i >= 0; i--) {
        std::string unitary_answer;
        int carry = 0;
        int operand1 = m_value[i] - '0';
        for (int j = num2.m_value.size() - 1; j >= 0 || carry != 0; j--) {
            int operand2 = (j >= 0) ? (num2.m_value[j] - '0') : (0);
            int result = operand1 * operand2 + carry;
            carry = result / 10;
            result %= 10;
            unitary_answer += char(result + 48);
        }
        unitary_answer = std::string(unitary_answer.rbegin(), unitary_answer.rend()) + std::string(unitary_results.size(), '0');
        unitary_results.push_back(RubberInt(unitary_answer));
    }
    RubberInt answer;
    for (unsigned int i = 0; i < unitary_results.size(); i++) {
        answer += unitary_results[i];
    }
    answer.m_isNegative = (m_isNegative != num2.m_isNegative);
    return answer;
}

RubberNumbers::RubberInt& RubberNumbers::RubberInt::operator*=(const RubberInt& num2)
{
    *this = *this * num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator/(const RubberInt& num2) const
{
    const RubberInt dividend = this->abs();
    const RubberInt divisor = num2.abs();
    RubberInt remainder;
    remainder.m_value = "";
    std::string cocient;
    unsigned int current_index = 0;
    while (current_index < dividend.m_value.size()) {
        if (current_index < dividend.m_value.size()) {
            remainder.m_value += dividend.m_value[current_index];
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
    cocient = (m_isNegative == num2.m_isNegative ? "" : "-") + cocient;
    return RubberInt(cocient);
}

RubberNumbers::RubberInt& RubberNumbers::RubberInt::operator/=(const RubberInt& num2)
{
    *this = *this / num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::operator%(const RubberInt& num2) const
{
    const RubberInt dividend = this->abs();
    const RubberInt divisor = num2.abs();
    RubberInt remainder;
    remainder.m_value = "";
    std::string cocient;
    unsigned int currentIndex = 0;
    while (currentIndex < dividend.m_value.size()) {
        if (currentIndex < dividend.m_value.size()) {
            remainder.m_value += dividend.m_value[currentIndex];
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

RubberNumbers::RubberInt& RubberNumbers::RubberInt::operator%=(const RubberInt& num2)
{
    *this = *this % num2;
    return *this;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::factorial() const
{
    if (m_isNegative) {
        throw std::invalid_argument("RubberInt::factorial(" + m_value + ")");
    }
    RubberInt result = 1;
    for (RubberInt i = m_value; i > 0; i--) {
        result *= i;
    }
    return result;
}

RubberNumbers::RubberInt RubberNumbers::RubberInt::abs() const
{
    if (!m_isNegative) {
        return *this;
    }
    return RubberInt(m_value);
}

std::string std::to_string(const RubberNumbers::RubberInt& num)
{
    return num.toString();
}

long long RubberNumbers::RubberInt::toLongLong() const
{
    if (*this > RubberInt(LONG_LONG_MAX)) {
        throw std::invalid_argument("RubberInt::toLongLong(" + this->toString() + ")");
    }
    return std::strtoll(((m_isNegative ? "-" : "") + m_value).c_str(), nullptr, 10);
}

unsigned long long RubberNumbers::RubberInt::toUnsignedLongLong() const
{
    if (*this > RubberInt(ULONG_LONG_MAX)) {
        throw std::invalid_argument("RubberInt::toUnsignedLongLong(" + this->toString() + ")");
    }
    return std::strtoull(((m_isNegative ? "-" : "") + m_value).c_str(), nullptr, 10);
}
