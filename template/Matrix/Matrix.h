#include <iostream>
#include <vector>
#include <type_traits>

template <typename T, bool is_const>
class Matrix {
private:
    typedef std::conditional_t<is_const, const T, T> element_t;

    std::vector<std::vector<element_t>> data;
    size_t rows;
    size_t cols;

public:
    // Конструктор по умолчанию
    Matrix() : rows(0), cols(0) {}

    // Конструктор с заданными размерами
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<element_t>(cols));
    }

    // Доступ к элементу матрицы по индексам
    element_t& operator()(size_t i, size_t j) {
        return data[i][j];
    }

    // Константный доступ к элементу матрицы по индексам
    const element_t& operator()(size_t i, size_t j) const {
        return data[i][j];
    }

    // Получение числа строк
    size_t getRows() const {
        return rows;
    }

    // Получение числа столбцов
    size_t getCols() const {
        return cols;
    }

    // Общий итератор для обхода элементов матрицы

    class Iterator {
    private:
        size_t row;
        size_t col;
        Matrix& matrix;
        bool is_const_iterator;

    public:
        Iterator(size_t row, size_t col, Matrix& matrix, bool is_const_iterator)
            : row(row), col(col), matrix(matrix), is_const_iterator(is_const_iterator) {}

        Iterator& operator++() {
            if (col < matrix.getCols() - 1) {
                ++col;
            } else {
                ++row;
                col = 0;
            }
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return row == other.row && col == other.col;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        std::conditional_t<is_const, const element_t&, element_t&> operator*() {
            return matrix(row, col);
        }

        // Оператор присваивания значений элементу матрицы
        Iterator& operator=(const element_t& value) {
            if (!is_const_iterator) {
                matrix(row, col) = value;
            }
            return *this;
        }

        // Оператор -> для доступа к членам структуры или класса T
        std::conditional_t<is_const, const T*, T*> operator->() {
            return &(matrix(row, col));
        }
    };

    Iterator begin() {
        return Iterator(0, 0, *this, false);
    }

    Iterator end() {
        return Iterator(rows, 0, *this, false);
    }

    Iterator cbegin() const {
        return Iterator(0, 0, *this, true);
    }

    Iterator cend() const {
        return Iterator(rows, 0, *this, true);
    }
};