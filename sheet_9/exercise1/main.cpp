#include <cmath>
#include "lambda.h"
#include "test.h"
#include <functional>
#include <iostream>

int main() {
    std::function<double(double)> lambda1 = [](double x){return 2*x + 5;};

    std::function<double(double)> lambda2 = [](double x) { return (x / M_PI * sin(x)); };

    std::cout << "Integration of f(x) = 2x + 5 from a=-3.0 to b=13.0 with an expected output of 240" << std::endl << std::endl;
    Trapez<double> integratorA(lambda1, Limits<double>(-3.0, 13.0));

    Test<double, Trapez<double>> t1(integratorA, 100, 240);
    t1.show();

    std::cout << "Integration of f(x) = x/pi * sin(x) from a=0.0 to b=" <<2*M_PI<< " with an expected output of -2" << std::endl << std::endl;
    Trapez<double> integratorD(lambda2, Limits<double>(0.0, 2*M_PI));

    Test<double, Trapez<double>> t2(integratorD, 100, -2);
    t2.show();
}
