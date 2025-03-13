#pragma once
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int** data;  // Двовимірний масив
    int rows;    // Кількість рядків
    int cols;    // Кількість стовпців
    int status;  // Код стану (0 - без помилок, 1 - помилка пам’яті, 2 - вихід за межі)

public:
    Matrix(int r, int c);  // Конструктор
    ~Matrix();             // Деструктор

    int getStatus() const;               // Отримання коду стану
    int getElement(int i, int j) const;  // Отримання значення елемента
    void setElement(int i, int j, int value);  // Встановлення значення елемента
    void print() const;                   // Вивід матриці
    void multiply(int scalar);             // Множення на число
};


