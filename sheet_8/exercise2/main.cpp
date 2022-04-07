#include "matrix_template.h"
#include<iostream>
#include <complex>
#include <iomanip>

int main()
{ // define matrix
    Matrix<2, 3, float> A(1);
    for (int i = 0; i < A.rows(); ++i)
        A[i][i] = 2.;
    for (int i=0; i < A.rows()-1; ++i)
        A[i+1][i] = A[i][i+1] = -1.;
    Matrix<3, 2, float> B(0.);
    for (int i = 0; i <B.cols(); ++i)
        B[i][i] = 2.;
    for (int i = 0; i < B.cols()-1; ++i)
        B[i+1][i] = B[i][i+1] = -1.;
    // print matrix
    A.print();
    B.print();
    Matrix<2, 3, float> C(A);
    A = float (2) * C;
    A.print();
    std::array<float, 3> k = {1,1,3};
    A = C * float(2);
    const std::array<float, 2> &Az = C * k;
    std::cout << Az;
    A.print();
    A = C + A;
    A.print();
    std::complex<float> complex_trial(1.0 , 2.0);
    const std::complex<float> &complex_out = C * complex_trial;
    std::cout << complex_out;
    C.print();
}
