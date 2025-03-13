#pragma once
#include <iostream>
#include <iomanip>

class LongLong {
private:
    long high; // ������ ������� �����
    unsigned long low;  // ������� ������� ����� (���������� ��� ����������� ������������)

public:
    // �����������
    LongLong(long h = 0, unsigned long l = 0);

    // ���������� ��������
    LongLong operator+(const LongLong& other) const;
    LongLong operator*(const LongLong& other) const;

    // �������� ���������
    bool operator<(const LongLong& other) const;
    bool operator>=(const LongLong& other) const;
    bool operator>(const LongLong& other) const;

    // ���� �����
    void print() const;
};




