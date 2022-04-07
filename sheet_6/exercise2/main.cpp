#include <cmath>
#include "integral.h"
#include "test.h"
#include <iostream>

int main() {
    Func1<double> funcA;
    std::cout << "Integration of f(x) = 2x + 5 from a=-3.0 to b=13.0 with an expected output of 240" << std::endl << std::endl;
    Trapez<double, Func1<double>> integratorA(funcA, Limits<double>(-3.0, 13.0));

    Test<double, Trapez<double, Func1<double>>> t1(integratorA, 100, 240);
    t1.show();

    Func2<double> funcB;
    std::cout << "Integration of f(x) = x/pi * sin(x) from a=0.0 to b=" <<2*M_PI<< " with an expected output of -2" << std::endl << std::endl;
    Trapez<double, Func2<double>> integratorD(funcB, Limits<double>(0.0, 2*M_PI));

    Test<double, Trapez<double, Func2<double>>> t2(integratorD, 100, -2);
    t2.show();
}