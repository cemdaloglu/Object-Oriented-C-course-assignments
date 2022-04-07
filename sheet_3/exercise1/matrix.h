#include "vector_broken.h"
#ifndef SHEET_1_MATRIX_H
#define SHEET_1_MATRIX_H
using namespace std;

class Matrix
{
public:
    double& operator()(int i, int j);
    std::vector<double>& operator[](int i);
    void resize(int row, int col, double value);
    void resize(Vector v);
    void resize(int row, int col);

    Matrix& operator*=(double x);
    Matrix& operator+=(Matrix& b);

    void print() const;

    Matrix(int row, int col){
        resize(row, col);
    }

    Matrix(int row, int col, double value){
        resize(row, col, value);
    }

    Matrix(Vector v){
        resize(v);
    }

    Matrix(int square_dim){
        resize(square_dim, square_dim);
    }

    int getRows()
    {
        return numRows;
    }

    int getCols()
    {
        return numCols;
    }
private:
    std::vector<std::vector<double>> matrix_entries;
    int numRows = 0;
    int numCols = 0;
};

Matrix operator+(Matrix& a, Matrix& b);
Matrix operator*(const Matrix& a, const int& b);
Matrix operator*(const int& b, const Matrix& a);
Matrix operator*(const Matrix& a, const Vector& b);
Matrix operator*(const Matrix& a, std::vector<double> b);

Matrix operator*(Matrix& a, Matrix& b);
#endif
