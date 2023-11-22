#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <utility>
#include <iterator>
#include <memory>


template <typename T>
struct MatrixIterator
{
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;

    MatrixIterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }

    pointer operator->() { return ptr_; }

    MatrixIterator& operator++()
    {
        ptr_++;
        return *this;
    }

    MatrixIterator operator++(int)
    {
        MatrixIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    MatrixIterator& operator--()
    {
        ptr_--;
        return *this;
    }

    MatrixIterator operator--(int)
    {
        MatrixIterator tmp = *this;
        --(*this);
        return tmp;
    }

    friend bool operator==(const MatrixIterator& a, const MatrixIterator& b)
    {
        return a.ptr_ == b.ptr_;
    }

    friend bool operator!=(const MatrixIterator& a, const MatrixIterator& b)
    {
        return a.ptr_ != b.ptr_;
    }
private:
    pointer ptr_;
};

template <typename T>
class Matrix
{
public:
    using Iterator = MatrixIterator<T>;
    using ConstIterator = MatrixIterator<const T>;
    using ReverseIterator = std::reverse_iterator<Iterator>;
    using ConstReverseIterator = std::reverse_iterator<ConstIterator>;
public:
    Matrix() : rows_(0), cols_(0), data_(nullptr) {}

    Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols),
                                       data_(std::make_unique<T[]>(size())) {}

    Matrix(const Matrix<T>& other) : rows_(other.rows_), cols_(other.cols_),
                                     data_(std::make_unique<T[]>(other.size()))   
    {
        std::copy(other.data_.get(), other.data_.get() + other.size(), data_.get());
    }

    Matrix(Matrix<T>&& other) noexcept : rows_(other.rows_), cols_(other.cols_),
                                         data_(std::move(other.data_))
    {
        other.rows_ = 0;
        other.cols_ = 0;
    }

    Matrix<T>& operator=(const Matrix<T>& other)
    {
        if (this == &other)
            return *this;
        
        if (size() != other.size())
        {
            rows_ = other.rows_;
            cols_ = other.cols_;
            data_ = std::make_unique<T[]>(other.size());
        }

        std::copy(other.data_.get(), other.data_.get() + other.size(), data_.get());
        return *this;
    }

    Matrix<T>& operator=(Matrix<T>&& other) noexcept
    {
        rows_ = std::exchange(other.rows_, 0);
        cols_ = std::exchange(other.cols_, 0);
        data_ = std::move(other.data_);
        return *this;
    }

    size_t rows() const noexcept { return rows_; }

    size_t cols() const noexcept { return cols_; }

    size_t size() const noexcept { return rows_ * cols_; }

    T& operator()(size_t row, size_t col)
    {
        return data_[row * cols_ + col];
    }

    const T& operator()(size_t row, size_t col) const
    {
        return data_[row * cols_ + col];
    }

    T& at(size_t row, size_t col)
    {
        if (row >= rows_ || col >= cols_)
            throw std::out_of_range("Index out of range");
        return (*this)(row, col);
    }

    const T& at(size_t row, size_t col) const
    {
        if (row >= rows_ || col >= cols_)
            throw std::out_of_range("Index out of range");
        return (*this)(row, col);
    }

    Iterator begin() { return Iterator(&data_[0]); }
    Iterator end() { return Iterator(&data_[size()]); }

    ConstIterator cbegin() { return ConstIterator(&data_[0]); }
    ConstIterator cend() { return ConstIterator(&data_[size()]); }

    ReverseIterator rbegin() { return ReverseIterator(&data_[size()]); }
    ReverseIterator rend() { return ReverseIterator(&data_[0]); }

    ConstReverseIterator crbegin() { return ConstReverseIterator(&data_[size()]); }
    ConstReverseIterator crend() { return ConstReverseIterator(&data_[0]); }
private:
    size_t rows_;
    size_t cols_;
    std::unique_ptr<T[]> data_;
};


#endif // MATRIX_H