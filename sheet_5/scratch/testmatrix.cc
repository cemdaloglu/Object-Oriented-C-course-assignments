/*#include "matrix_template.h"
#include<iostream>
#include <complex>
#include <iomanip>
//#include "simple_matrix.h"
//#include "num_matrix.h"

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
  std::cout << complex_out << std::endl;

  std::vector<float> vector_trial(1, 1);
  const std::vector<float> &vector_out = A * vector_trial;
  std::cout << vector_out << std::endl;

  Matrix<2, 3, Rational> R(Rational(1, 6));
  for (int i = 0; i < R.rows(); ++i)
      R[i][i] = Rational(1, 2);

  std::array<Rational, 3> rational_trial = {Rational(1, 3), Rational(1, 1), Rational(1, 1)};
  const std::array<Rational, 2> &rati_out = R * rational_trial;
  std::cout << rati_out;
  R.print();

  /*SimpleMatrix<2, 3, std::string> Sa("a");
    Sa.print();
  for (int i = 0; i < Sa.rows(); ++i)
      Sa[i][i] = 2.;
  for (int i=0; i < Sa.rows()-1; ++i)
      Sa[i+1][i] = Sa[i][i+1] = -1.;
    Sa.print();

    Matrix<SimpleMatrix<1, 2, float>, 2, float> A(1);

    SimpleMatrix<2, 3, float> Sb(1);
    for (int i = 0; i < Sb.rows(); ++i)
        Sb[i][i] = 2.;
    for (int i=0; i < Sb.rows()-1; ++i)
        Sb[i+1][i] = Sb[i][i+1] = -1.;
    Sb.print();*/

    /*Matrix<2, 3, float> Sc;
    Sc = Sa + Sb;
    Sc.print();*/
  /*const Matrix<float> D(A);
  std::cout << "Element 1,1 of D is " << D(1,1) << std::endl;
  std::cout << std::endl;
  A.resize(5,5,0.);
  for (int i = 0; i < A.rows(); ++i)  
    A(i,i) = 2.;
  for (int i = 0; i < A.rows()-1; ++i) 
    A(i+1,i) = A(i,i+1) = -1.;
  // define vector b
  std::vector<float> b(5);
  b[0] = b[4] = 5.;
  b[1] = b[3] = -4.;
  b[2] = 4.;
  std::vector<float> x = A * b;
  std::cout << "A*b = ( ";
  for (size_t i = 0; i < x.size(); ++i)
    std::cout << x[i] << "  ";
  std::cout << ")" << std::endl;
  std::cout << std::endl;
}*/
