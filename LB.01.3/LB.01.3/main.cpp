#include <iostream>
#include "longLong.h"

int main() {
    LongLong num1(1, 2000000000);
    LongLong num2(2, 1000000000);

    std::cout << "Number 1: ";
    num1.print();

    std::cout << "Number 2: ";
    num2.print();

    // Додавання
    LongLong sum = num1 + num2;
    std::cout << "Sum: ";
    sum.print();

    // Множення
    LongLong product = num1 * num2;
    std::cout << "Product: ";
    product.print();

    // Порівняння
    std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
    std::cout << "num1 >= num2: " << (num1 >= num2) << std::endl;
    std::cout << "num1 > num2: " << (num1 > num2) << std::endl;

    return 0;
}

