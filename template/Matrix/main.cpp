#include <iostream>
#include "Matrix.h"



int main() {
    // Пример использования
    Matrix<int, false> mutableMatrix(3, 3);

    int value = 1;
    for (auto it = mutableMatrix.begin(); it != mutableMatrix.end(); ++it) {
        *it = value++;
    }

    // Выводим значения через оператор *
    for (auto it = mutableMatrix.begin(); it != mutableMatrix.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
