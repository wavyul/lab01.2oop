#pragma once
#include <iostream>
#include <iomanip>

class LongLong {
private:
    long high; // Старша частина числа
    unsigned long low;  // Молодша частина числа (беззнакове для правильного переповнення)

public:
    // Конструктор
    LongLong(long h = 0, unsigned long l = 0);

    // Арифметичні операції
    LongLong operator+(const LongLong& other) const;
    LongLong operator*(const LongLong& other) const;

    // Операції порівняння
    bool operator<(const LongLong& other) const;
    bool operator>=(const LongLong& other) const;
    bool operator>(const LongLong& other) const;

    // Вивід числа
    void print() const;
};




