#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

/**
 * @brief Contains the classes of Rubber Numbers, which is a library to handle arbitrarily-sized numbers.
 */
namespace RubberNumbers {
/**
 * @brief Represents the error caused by trying to divide by 0.
 */
class RubberDivisionByZero : public std::runtime_error {
    /**
     * @brief Creates a new DivisionByZero error object.
     */
    RubberDivisionByZero();
};

/**
 * @brief Represents an arbitrarily-sized integer.
 */
class RubberInt {
private:
    std::string m_value;
    bool m_isNegative;

    /**
     * @brief Checks if given string is valid to initialize a RubberInt.
     * @param str A std::string.
     * @return True if the given string is valid to initialize a RubberInt, false otherwise.
     */
    static bool isValidInput(const std::string& str);

    /**
     * @brief Deletes trailing zeroes from this RubberInt.
     */
    void deleteTrailingZeroes();

public:
    /**
     * @brief Creates a new RubberInt with value of 0.
     * @return A RubberInt with the value of 0.
     */
    RubberInt();

    /**
     * @brief Creates a new RubberInt with the value represented by the given string.
     * @param value A std::string that represents an integer value.
     * @return A RubberInt with the value represented by the given string.
     * @throws Throws std::invalid_argument if the std::string has a value that is not a valid
     *         integer number.
     */
    RubberInt(const std::string& value);

    /**
     * @brief Creates a new RubberInt with the given value.
     * @tparam IntType A type of number that is integral (e.g. int, long long).
     * @param value An integer value of type IntType.
     * @return A RubberInt with the given value.
     */
    template <typename IntType, typename = typename std::enable_if<std::is_integral<IntType>::value>::type>
    RubberInt(const IntType value)
    {
        *this = RubberInt(std::to_string(value));
    }

    /**
     * @brief Compares this RubberInt to another RubberInt for equality.
     * @param num2 A RubberInt to check for equality.
     * @return True if both values represent the same integer value, false otherwise.
     */
    bool operator==(const RubberInt& num2) const;

    /**
     * @brief Compares this RubberInt to another RubberInt for inequality.
     * @param num2 A RubberInt to check for inequality.
     * @return True if both values represent different integer values, false otherwise.
     */
    bool operator!=(const RubberInt& num2) const;

    /**
     * @brief Checks if this RubberInt is greater than another RubberInt.
     * @param num2 A RubberInt to compare.
     * @return True if the value of this RubberInt is greater than the value of the second, false otherwise.
     */
    bool operator>(const RubberInt& num2) const;

    /**
     * @brief Checks if this RubberInt is lower than another RubberInt.
     * @param num2 A RubberInt to compare.
     * @return True if the value of this RubberInt is less than the value of the given RubberInt, false otherwise.
     */
    bool operator<(const RubberInt& num2) const;

    /**
     * @brief Checks if this RubberInt is greater than or equal to another RubberInt.
     * @param num2 A RubberInt to compare.
     * @return True if the value of this RubberInt greater than or equal to the value of the given RubberInt, false
     *         otherwise.
     */
    bool operator>=(const RubberInt& num2) const;

    /**
     * @brief Checks if this RubberInt is less than or equal to another RubberInt.
     * @param num2 A RubberInt to compare.
     * @return True if the value of the first is less than or equal to the value of the second, false otherwise.
     */
    bool operator<=(const RubberInt& num2) const;

    /**
     * @brief Computes the sum of two RubberInts.
     * @param num2 A RubberInt to sum to this one.
     * @return A new RubberInt with the sum of the two RubberInts.
     */
    RubberInt operator+(const RubberInt& num2) const;

    /**
     * @brief Computes the sum of two RubberInts, modifying this one in place.
     * @param num2 A RubberInt to sum to this one.
     * @return A reference to this RubberInt, which has the sum of the two RubberInts.
     */
    RubberInt& operator+=(const RubberInt& num2);

    /**
     * @brief Computes the difference of two RubberInts.
     * @param num2 A RubberInt to subtract from this one.
     * @return A new RubberInt with the difference of the two RubberInts.
     */
    RubberInt operator-(const RubberInt& num2) const;

    /**
     * @brief Computes the difference of two RubberInts, modifying this one in place.
     * @param num2 A RubberInt to subtract from this one.
     * @return A reference to this RubberInt, which has the difference of the two RubberInts.
     */
    RubberInt& operator-=(const RubberInt& num2);

    /**
     * @brief Increases the value of this RubberInt by one, and then returns its previous value.
     * @return A RubberInt with the value of this before the operation.
     */
    RubberInt operator++(int);

    /**
     * @brief Decreases the value of this RubberInt by one, and then returns its previous value.
     * @return A RubberInt with the value of this before the operation.
     */
    RubberInt operator--(int);

    /**
     * @brief Increases the value of this RubberInt by one, and then returns a reference to it.
     * @return A reference to this RubberInt.
     */
    RubberInt& operator++();

    /**
     * @brief Decreases the value of this RubberInt by one, and then returns a reference to it.
     * @return A reference to this RubberInt.
     */
    RubberInt& operator--();

    /**
     * @brief Computes the product of two RubberInts.
     * @param num2 A RubberInt to multiply to this one.
     * @return A new RubberInt with the product of the two RubberInts.
     */
    RubberInt operator*(const RubberInt& num2) const;

    /**
     * @brief Computes the product of two RubberInts, modifying this one in place.
     * @param num2 A RubberInt to multiply to this one.
     * @return A reference to this RubberInt, which has the product of the two RubberInts.
     */
    RubberInt& operator*=(const RubberInt& num2);

    /**
     * @brief Computes the quotient of two RubberInts.
     * @param num2 A RubberInt to divide this one by.
     * @return A new RubberInt with the quotient of the two RubberInts.
     * @throws RubberDivisionByZero if num2 is zero.
     */
    RubberInt operator/(const RubberInt& num2) const;

    /**
     * @brief Computes the product of two RubberInts, modifying this one in place.
     * @param num2 A RubberInt to divide this one by.
     * @return A reference to this RubberInt, which has the quotient of the two RubberInts.
     * @throws RubberDivisionByZero if num2 is zero.
     */
    RubberInt& operator/=(const RubberInt& num2);

    /**
     * @brief Computes the remainder of two RubberInts.
     * @param num2 A RubberInt to divide this one by.
     * @return A new RubberInt with the remainder of the two RubberInts.
     * @throws RubberDivisionByZero if num2 is zero.
     */
    RubberInt operator%(const RubberInt& num2) const;

    /**
     * @brief Computes the remainder of two RubberInts, modifying this one in place.
     * @param num2 A RubberInt to divide this one by.
     * @return A reference to this RubberInt, which has the remainder of the two RubberInts.
     * @throws RubberDivisionByZero if num2 is zero.
     */
    RubberInt& operator%=(const RubberInt& num2);

    /**
     * @brief Computes the factorial of this RubberInt.
     * @return A new RubberInt with the factorial of this one.
     */
    RubberInt factorial() const;

    /**
     * @brief Computes the absolute value of this RubberInt.
     * @return A new RubberInt with the absolute value of this one.
     */
    RubberInt abs() const;

    /**
     * @brief Produces a string representation of the value of this RubberInt.
     * @return A std::string with the value represented by this RubberInt.
     */
    std::string toString() const;

    /**
     * @brief Produces a long long with the value of this RubberInt.
     * @return A long long with the value represented by this RubberInt.
     * @throw std::invalid_argument if value is not representable by a long long.
     */
    long long toLongLong() const;

    /**
     * @brief Produces an unsigned long long with the value of this RubberInt.
     * @return An unsigned long long with the value represented by this RubberInt.
     * @throw std::invalid_argument if value is not representable by an unsigned long long.
     */
    unsigned long long toUnsignedLongLong() const;
};

/**
 * @brief Streams a string representation for this RubberInt into the given ostream.
 * @param stream A reference to a std::ostream to stream to.
 * @param num A RubberInt to stream.
 * @return A reference to the std::ostream after the operation.
 */
std::ostream& operator<<(std::ostream& stream, const RubberInt& num);

/**
 * @brief Consumes a string representation and sets the value of this RubberInt to that.
 * @param stream A reference to a std::istream to consume characters from.
 * @param num A RubberInt to save the reading of the stream.
 * @return A reference to the std::istream after the operation.
 */
std::istream& operator>>(std::istream& stream, RubberInt& num);
}

#ifndef RUBBER_NUMBERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
namespace std {
/**
 * @brief Produces a string interpretation of this RubberInt.
 * @param A RubberInt to convert to string.
 * @return A std::string with the value of the RubberInt.
 */
string to_string(const RubberNumbers::RubberInt& num);
}
#endif // RUBBER_INTEGERS__DO_NOT_SPECIALIZE_STANDARD_LIBRARY
