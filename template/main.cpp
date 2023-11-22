#include <iostream>
#include "Matrix.h"


int main() {
    Matrix<int> m(2, 3);
    std::cout << m(0, 0);
    /*int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            m.setMij(i, j, i + j);

    m.print_m();


    Matrix<int> m2 = m;
    m2.print_m();

    Matrix<int> m3;
    m3 = m;
    m3.print_m();
*/
}