#include "longLong.h"

LongLong::LongLong(long h, unsigned long l) : high(h), low(l) {}

// Операція додавання
LongLong LongLong::operator+(const LongLong& other) const {
    unsigned long newLow = low + other.low;
    long newHigh = high + other.high;

    if (newLow < low) { // Переповнення молодшої частини
        newHigh++;
    }

    return LongLong(newHigh, newLow);
}

// Операція множення
LongLong LongLong::operator*(const LongLong& other) const {
    unsigned long long fullLow = static_cast<unsigned long long>(low) * other.low;
    unsigned long long fullMid1 = static_cast<unsigned long long>(high) * other.low;
    unsigned long long fullMid2 = static_cast<unsigned long long>(low) * other.high;
    unsigned long long fullHigh = static_cast<unsigned long long>(high) * other.high;

    unsigned long newLow = static_cast<unsigned long>(fullLow);
    long newHigh = static_cast<long>(fullHigh + (fullMid1 >> 32) + (fullMid2 >> 32));

    return LongLong(newHigh, newLow);
}

// Операція порівняння "<"
bool LongLong::operator<(const LongLong& other) const {
    return (high < other.high) || (high == other.high && low < other.low);
}

// Операція порівняння ">="
bool LongLong::operator>=(const LongLong& other) const {
    return !(*this < other);
}

// Операція порівняння ">"
bool LongLong::operator>(const LongLong& other) const {
    return (high > other.high) || (high == other.high && low > other.low);
}

// Вивід числа з форматуванням
void LongLong::print() const {
    std::cout << "LongLong(" << high << ", " << std::setw(10) << std::setfill('0') << low << ")" << std::endl;
}
