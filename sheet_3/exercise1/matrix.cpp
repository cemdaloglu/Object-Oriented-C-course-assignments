#include "matrix.h"
#include<iomanip>
#include<iostream>
#include<cstdlib>

void Matrix::resize(int row, int col) {
    std::vector<std::vector<double>> matrix(row);
    for (int i = 0; i < row; ++i) {
        matrix[i].resize(col);
    }
    matrix_entries = matrix;
    numRows = row;
    numCols = col;
}

void Matrix::resize(int row, int col, double value) {
    std::vector<std::vector<double>> matrix(row);
    for (int i = 0; i < row; ++i) {
        matrix[i].resize(col);
    }
    matrix_entries = matrix;
    for (int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j)
            matrix_entries[i][j] = value;
    }
    numRows = row;
    numCols = col;
}

void Matrix::resize(Vector v) {
    std::vector<std::vector<double>> matrix(1);
    for (int i = 0; i < 1; ++i) {
        matrix[i].resize(v.size());
    }
    matrix_entries = matrix;
    for (int i = 0; i < 1; ++i) {
        for(int j = 0; j < v.size(); ++j)
            matrix_entries[i][j] = v[j];
    }
    numRows = 1;
    numCols = v.size();
}

double& Matrix::operator()(int i, int j)
{
    if (i < 0 || i >= numRows || j < 0 || j >= numCols)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix_entries[i][j];
}

std::vector<double>& Matrix::operator[](int i)
{
    if (i < 0 || i >= numRows)
    {
        std::cerr << "Illegal index " << i;
        std::cerr << " valid range is [0:" << numRows-1 << "]";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix_entries[i];
}


Matrix& Matrix::operator+=(Matrix& b)
{
    if (b.numRows != numRows || b.numCols != numCols)
    {
        std::cerr << "Dimensions of vector a (" << numRows
                  << ") and vector b (" << b.numRows
                  << ") do not match!";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix_entries[i][j] += b[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(double x)
{
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix_entries[i][j] *= x;
        }
    }
    return *this;
}

Matrix operator*(Matrix& a, Matrix& b) // multiplication for matrices Mx1 * 1xK dimensions
{
    if (b.getRows() != a.getCols())
    {
        std::cerr << "Dimensions of vector a (" << b.getRows()
                  << ") and vector b (" << b.getRows()
                  << ") do not match!";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix output(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < b.getCols(); ++j) {
            output[i][j] = a[i][0] * b[0][j];
        }
    }
    return output;
}

Matrix operator+(Matrix& a, Matrix& b)
{
    Matrix output(a);
    output += b;
    return output;
}

Matrix operator*(const Matrix& a, const int& b)
{
    Matrix output(a);
    output *= b;
    return output;
}


Matrix operator*(const int& b, const Matrix& a)
{
    Matrix output(a);
    output *= b;
    return output;
}
Matrix operator*(const Matrix& a, const Vector& v)
{
    Matrix first(a);
    Matrix second(v);
    Matrix output = first * second;
    return output;
}
Matrix operator*(const Matrix& a, std::vector<double> b)
{
    Vector v(b);
    Matrix first(a);
    Matrix second(v);
    Matrix output = first * second;
    return output;
}

void Matrix::print() const
{
    std::cout << "(" << numRows << "," << numCols << ") matrix:" << std::endl;
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j) {
            std::cout << std::setprecision(3);
            std::cout << std::setw(5) << matrix_entries[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
