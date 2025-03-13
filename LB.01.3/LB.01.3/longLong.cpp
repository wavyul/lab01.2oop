#include "longLong.h"

LongLong::LongLong(long h, unsigned long l) : high(h), low(l) {}

// �������� ���������
LongLong LongLong::operator+(const LongLong& other) const {
    unsigned long newLow = low + other.low;
    long newHigh = high + other.high;

    if (newLow < low) { // ������������ ������� �������
        newHigh++;
    }

    return LongLong(newHigh, newLow);
}

// �������� ��������
LongLong LongLong::operator*(const LongLong& other) const {
    unsigned long long fullLow = static_cast<unsigned long long>(low) * other.low;
    unsigned long long fullMid1 = static_cast<unsigned long long>(high) * other.low;
    unsigned long long fullMid2 = static_cast<unsigned long long>(low) * other.high;
    unsigned long long fullHigh = static_cast<unsigned long long>(high) * other.high;

    unsigned long newLow = static_cast<unsigned long>(fullLow);
    long newHigh = static_cast<long>(fullHigh + (fullMid1 >> 32) + (fullMid2 >> 32));

    return LongLong(newHigh, newLow);
}

// �������� ��������� "<"
bool LongLong::operator<(const LongLong& other) const {
    return (high < other.high) || (high == other.high && low < other.low);
}

// �������� ��������� ">="
bool LongLong::operator>=(const LongLong& other) const {
    return !(*this < other);
}

// �������� ��������� ">"
bool LongLong::operator>(const LongLong& other) const {
    return (high > other.high) || (high == other.high && low > other.low);
}

// ���� ����� � �������������
void LongLong::print() const {
    std::cout << "LongLong(" << high << ", " << std::setw(10) << std::setfill('0') << low << ")" << std::endl;
}
