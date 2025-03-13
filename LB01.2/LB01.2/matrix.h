#pragma once
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int** data;  // ���������� �����
    int rows;    // ʳ������ �����
    int cols;    // ʳ������ ��������
    int status;  // ��� ����� (0 - ��� �������, 1 - ������� �����, 2 - ����� �� ���)

public:
    Matrix(int r, int c);  // �����������
    ~Matrix();             // ����������

    int getStatus() const;               // ��������� ���� �����
    int getElement(int i, int j) const;  // ��������� �������� ��������
    void setElement(int i, int j, int value);  // ������������ �������� ��������
    void print() const;                   // ���� �������
    void multiply(int scalar);             // �������� �� �����
};


