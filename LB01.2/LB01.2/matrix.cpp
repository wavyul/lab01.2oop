#include "matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c), status(0) {
    data = new (std::nothrow) int* [rows];  // Виділення пам'яті для рядків
    if (!data) {
        status = 1;  // Помилка пам'яті
        return;
    }

    for (int i = 0; i < rows; ++i) {
        data[i] = new (std::nothrow) int[cols];  // Виділення пам'яті для стовпців
        if (!data[i]) {
            status = 1;  // Помилка пам'яті
            return;
        }
    }
}

// Деструктор
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Отримання коду стану
int Matrix::getStatus() const {
    return status;
}

// Отримання елемента матриці
int Matrix::getElement(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        return 2;  // Вихід за межі матриці
    }
    return data[i][j];
}

// Встановлення значення елемента
void Matrix::setElement(int i, int j, int value) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        status = 2;  // Вихід за межі
        return;
    }
    data[i][j] = value;
}

// Вивід матриці
void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Множення матриці на число
void Matrix::multiply(int scalar) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] *= scalar;
        }
    }
}

