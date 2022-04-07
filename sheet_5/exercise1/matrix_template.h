#ifndef SOLUTIONS_MATRIX_TEMPLATE_H
#define SOLUTIONS_MATRIX_TEMPLATE_H
#include<iomanip>
#include<iostream>
#include<cstdlib>
#include<vector>
#include <iterator>
#include "rational_numbers.hpp"

template<std::size_t numRows, std::size_t numCols, typename T>

class Matrix
{
public:
    Matrix();
    Matrix(T value);
    Matrix(const Matrix<numRows, numCols, T>& b);
    // access elements
    T& operator()(int i, int j);
    T  operator()(int i, int j) const;
    T* operator[](int i);
    const T* operator[](int i) const;
    // arithmetic functions
    Matrix<numRows, numCols, T>& operator*=(T x);
    Matrix<numRows, numCols, T>& operator+=(const Matrix<numRows, numCols, T>& b);
    // output
    void print() const;
    int rows() { return numRows; };
    int cols() { return numCols; };
private:
    //std::vector<std::vector<T>> entries{};
    T **entries;
};

#endif

template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T>::Matrix()
{
    entries = new T*[numRows];
    for (size_t i = 0; i < numRows; ++i)
    {
        entries[i] = new T[numCols];
        for (size_t j = 0; j < numCols; ++j)
            entries[i][j] = 0;
    }
}


template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T>::Matrix(T value)
{
    entries = new T*[numRows];
    for (size_t i = 0; i < numRows; ++i)
    {
        entries[i] = new T[numCols];
        for (size_t j = 0; j < numCols; ++j)
            entries[i][j] = value;
    }
}


template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T>::Matrix(const Matrix<numRows, numCols, T>& b)
{
    entries = new T*[numRows];
    for (size_t i = 0; i < numRows; ++i)
    {
        entries[i] = new T[numCols];
        for (size_t j = 0; j < numCols; ++j)
            entries[i][j] = b[i][j];
    }
}

template<std::size_t numRows, std::size_t numCols, typename T>
T& Matrix<numRows, numCols, T>::operator()(int i, int j)
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols)
    {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is [0:" << numCols-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

template<std::size_t numRows, std::size_t numCols, typename T>
T Matrix<numRows, numCols, T>::operator()(int i, int j) const
{
    if ( i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if (j < 0 || j >= numCols)
    {
        std::cerr << "Illegal column index " << j;
        std::cerr << " valid range is [0:" << numCols-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i][j];
}

template<std::size_t numRows, std::size_t numCols, typename T>
T* Matrix<numRows, numCols, T>::operator[](int i)
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}

template<std::size_t numRows, std::size_t numCols, typename T>
const T* Matrix<numRows, numCols, T>::operator[](int i) const
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal row index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return entries[i];
}


template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T>& Matrix<numRows, numCols, T>::operator*=(T x)
{
    for (int i = 0; i < numRows; ++i)
        for (int j = 0; j < numCols; ++j)
            entries[i][j] *= x;
    return *this;
}

template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T>& Matrix<numRows, numCols, T>::operator+=(const Matrix<numRows, numCols, T>& x)
{
    for (int i = 0; i < numRows; ++i)
        for (int j = 0;j < numCols; ++j)
            entries[i][j] += x[i][j];
    return *this;
}


template<std::size_t numRows, std::size_t numCols, typename T>
void Matrix<numRows, numCols, T>::print() const
{
    std::cout << "(" << numRows << "x";
    std::cout << numCols << ") matrix:" << std::endl;
    for (int i = 0; i < numRows; ++i)
    {
        std::cout << std::setprecision(3);
        for (int j = 0; j < numCols; ++j)
            std::cout << std::setw(5) << entries[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T> operator*(const Matrix<numRows, numCols, T>& a, T x)
{
    Matrix<numRows, numCols, T> output(a);
    output *= x;
    return output;
}

template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T> operator*(T x, const Matrix<numRows, numCols, T>& a)
{
    Matrix<numRows, numCols, T> output(a);
    output *= x;
    return output;
}

template<std::size_t numRows, std::size_t numCols, template<typename>class H, typename T>
H<T> operator*(const Matrix<numRows, numCols, T>& a,
               const H<T>& x)
{
    H<T> output;
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
            output += a[i][j] * x;
    }
    return output;
}

template<std::size_t numRows, std::size_t numCols, template<typename, size_t >class H, typename T>
H<T, numRows> operator*(const Matrix<numRows, numCols, T>& a,
                        const H<T, numCols>& x)
{
    H<T, numRows> output;

    for (int i = 0; i < numRows; ++i) {
        output[i] = T(0);
        for (int j = 0; j < numCols; ++j)
            output[i] += T(a[i][j] * x[j]);
    }
    return output;
}

template<std::size_t numRows, std::size_t numCols, typename T>
Matrix<numRows, numCols, T> operator+(const Matrix<numRows, numCols, T>& a, const Matrix<numRows, numCols, T>& b)
{
    Matrix<numRows, numCols, T> output(a);
    output += b;
    return output;
}

template <class T, std::size_t N>
std::ostream& operator<<(std::ostream& o, const std::array<T, N>& arr)
{
    std::cout << "(" << 1 << "x";
    std::cout << N << ") matrix:" << std::endl;

    for (int i = 0; i < 1; ++i)
    {
        std::cout << std::setprecision(3);
        for (int j = 0; j < N; ++j)
            std::cout << std::setw(5) << arr[j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return o;
}