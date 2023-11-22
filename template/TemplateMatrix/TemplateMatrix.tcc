#include "TemplateMatrix.h"


template <typename T>
Matrix<T>::Matrix() {
    this->rows = 0;
    this->columns = 0;
    this->matrix = nullptr; 
}


template <typename T>
Matrix<T>::Matrix(int m, int n) {
    this->rows = m;
    this->columns = n;
    this->matrix;
}


template <typename T>
Matrix<T>::Matrix(const Matrix &other) {
    this->columns = other.columns;
    this->rows = other.rows;
    this->matrix = std::copy(other.matrix.begin(), other.matrix.end(), this->matrix.begin());
}


template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix &other) {
    columns = other.columns;
    rows = other.rows;
    this->matrix = std::copy(other.matrix.begin(), other.matrix.end(), this->matrix.begin());
}


//template <typename T>
//Matrix<T>::~Matrix() {}


template <typename T>
void Matrix<T>::setMij(int i, int j, T value) {
    if (i < 0 || i >= rows || j < 0 || j >= columns)
        return;
    matrix[i][j] = value;
}


template <typename T>
void Matrix<T>::print_m()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "+++++++++++++++" << std::endl << std::endl;
}
