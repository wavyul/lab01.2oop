#include "matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c), status(0) {
    data = new (std::nothrow) int* [rows];  // �������� ���'�� ��� �����
    if (!data) {
        status = 1;  // ������� ���'��
        return;
    }

    for (int i = 0; i < rows; ++i) {
        data[i] = new (std::nothrow) int[cols];  // �������� ���'�� ��� ��������
        if (!data[i]) {
            status = 1;  // ������� ���'��
            return;
        }
    }
}

// ����������
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// ��������� ���� �����
int Matrix::getStatus() const {
    return status;
}

// ��������� �������� �������
int Matrix::getElement(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        return 2;  // ����� �� ��� �������
    }
    return data[i][j];
}

// ������������ �������� ��������
void Matrix::setElement(int i, int j, int value) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        status = 2;  // ����� �� ���
        return;
    }
    data[i][j] = value;
}

// ���� �������
void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// �������� ������� �� �����
void Matrix::multiply(int scalar) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] *= scalar;
        }
    }
}

