#include "matrix.h"
#include<iostream>
using namespace std;

int main() {
    Matrix a(5,4);
    Matrix b(5, 4, 1);
    a.print();
    b.print();

    a = b + b;
    a.print();
    a(0,0) = 5;
    a.print();
    a[1] = b[2];
    a.print();

    a = b * 3;
    a.print();

    a = 5 * b;
    a.print();

    Matrix e(5, 1, -1);
    Vector c(4, 7);
    a = e * c;
    a.print();

    std::vector<double> d = {1, 2, 3, 4};
    a = e * d;
    a.print();
}
