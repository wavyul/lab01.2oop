#include <iostream>
#include "matrix.h"
using namespace std;
int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    Matrix matrix(rows, cols);
    if (matrix.getStatus() == 1) {
       cerr << "Error: Not enough storage!" << endl;
        return 1;
    }

   cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
           cin >> value;
            matrix.setElement(i, j, value);
        }
    }

   cout << "Your matrix:\n";
    matrix.print();

    int scalar;
   cout << "Enter the number to multiply: ";
    cin >> scalar;

    matrix.multiply(scalar);

   cout << "Matrix after multiplication::\n";
    matrix.print();

    return 0;
}
