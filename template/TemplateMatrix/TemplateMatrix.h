#include <iostream>
#include <memory>

template <typename T>
class Matrix {
private:
    int rows;
    int cols;
    std::unique_ptr<T[]> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols), data(new T[rows * cols]) {}

    T& operator()(int row, int col) {
        return data[row * cols + col];
    }

    const T& operator()(int row, int col) const {
        return data[row * cols + col];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    class Iterator {
    private:
        T* ptr;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(T* ptr) : ptr(ptr) {}

        reference operator*() const {
            return *ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }

        Iterator& operator--() {
            --ptr;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            --ptr;
            return temp;
        }

        Iterator& operator+=(difference_type n) {
            ptr += n;
            return *this;
        }

        Iterator operator+(difference_type n) const {
            return Iterator(ptr + n);
        }

        Iterator& operator-=(difference_type n) {
            ptr -= n;
            return *this;
        }

        Iterator operator-(difference_type n) const {
            return Iterator(ptr - n);
        }

        difference_type operator-(const Iterator& other) const {
            return ptr - other.ptr;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        bool operator<(const Iterator& other) const {
            return ptr < other.ptr;
        }

        bool operator>(const Iterator& other) const {
            return ptr > other.ptr;
        }

        bool operator<=(const Iterator& other) const {
            return ptr <= other.ptr;
        }

        bool operator>=(const Iterator& other) const {
            return ptr >= other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(data.get());
    }

    Iterator end() {
        return Iterator(data.get() + rows * cols);
    }
};

