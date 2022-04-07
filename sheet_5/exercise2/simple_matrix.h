#ifndef SOLUTIONS_SIMPLE_MATRIX_H
#define SOLUTIONS_SIMPLE_MATRIX_H
#include<iomanip>
#include<iostream>
#include<cstdlib>
#include<vector>
#include <iterator>
#include "rational_numbers.hpp"
#include "matrix_template.h"

template<std::size_t numRows, std::size_t numCols, typename T>

class SimpleMatrix : public Matrix<numRows, numCols, T>
{
public:
    SimpleMatrix();
    SimpleMatrix(T value);
    SimpleMatrix(const SimpleMatrix<numRows, numCols, T>& b);
    // access elements
    T operator()(int i, int j) const;
    T& operator()(int i, int j);
    T* operator[](int i);
    const T* operator[](int i) const;
    // output
    void print() const;
    int rows() { return numRows; };
    int cols() { return numCols; };
private:
    T **entries;
};

#endif

template<std::size_t numRows, std::size_t numCols, typename T>
SimpleMatrix<numRows, numCols, T>::SimpleMatrix()

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
SimpleMatrix<numRows, numCols, T>::SimpleMatrix(T value)
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
SimpleMatrix<numRows, numCols, T>::SimpleMatrix(const SimpleMatrix<numRows, numCols, T>& b)
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
T& SimpleMatrix<numRows, numCols, T>::operator()(int i, int j)
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
T SimpleMatrix<numRows, numCols, T>::operator()(int i, int j) const
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
T* SimpleMatrix<numRows, numCols, T>::operator[](int i)
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
const T* SimpleMatrix<numRows, numCols, T>::operator[](int i) const
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
void SimpleMatrix<numRows, numCols, T>::print() const
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