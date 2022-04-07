#ifndef SOLUTIONS_NUM_MATRIX_H
#define SOLUTIONS_NUM_MATRIX_H

#include<iomanip>
#include<iostream>
#include<cstdlib>
#include<vector>
#include <iterator>
#include "rational_numbers.hpp"
#include "simple_matrix.h"

template<std::size_t numRows, std::size_t numCols, typename T>

class NumMatrix
{
public:
    SimpleMatrix<numRows, numCols, T>& operator*=(T x);
    SimpleMatrix<numRows, numCols, T>& operator+=(const SimpleMatrix<numRows, numCols, T>& b);
private:
    T **entries;
};

#endif

template<std::size_t numRows, std::size_t numCols, typename T>
SimpleMatrix<numRows, numCols, T> operator*(const SimpleMatrix<numRows, numCols, T>& a, T x)
{
    SimpleMatrix<numRows, numCols, T> output(a);
    output *= x;
    return output;
}

template<std::size_t numRows, std::size_t numCols, typename T>
SimpleMatrix<numRows, numCols, T> operator*(T x, const SimpleMatrix<numRows, numCols, T>& a)
{
    SimpleMatrix<numRows, numCols, T> output(a);
    output *= x;
    return output;
}

template<std::size_t numRows, std::size_t numCols, template<typename>class H, typename T>
H<T> operator*(const SimpleMatrix<numRows, numCols, T>& a,
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
H<T, numRows> operator*(const SimpleMatrix<numRows, numCols, T>& a,
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
SimpleMatrix<numRows, numCols, T> operator+(const SimpleMatrix<numRows, numCols, T>& a, const SimpleMatrix<numRows, numCols, T>& b)
{
    SimpleMatrix<numRows, numCols, T> output(a);
    output += b;
    return output;
}
/*
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
}*/