#ifndef SOLUTIONS_TEST_LAMBDA_H
#define SOLUTIONS_TEST_LAMBDA_H
#include<cmath>

template<typename T, class I>
class Test_lambda
{
    T exact_sol;
    int n;
    I integral;
public:

    Test_lambda(I &integral, int n_, T exact_sol_) :
            exact_sol{exact_sol_},
            n{n_},
            integral{integral}
    {}

    void show_lambda()
    {
        T approx_sol1, approx_sol2, error1, error2, EOC;
        approx_sol1 = rule1<T>(n, integral.limits_, integral.composite_rule, integral.integrand_);
        error1 = std::abs(approx_sol1 - exact_sol);
        std::cout << "\tn = " << n <<", approximate solution = " << approx_sol1 << ", exact solution = "<< exact_sol << std::endl;
        int limit = 10 * n;
        while(n <= limit)
        {
            n = 2 * n;
            approx_sol2 = rule1<T>(n, integral.limits_, integral.composite_rule, integral.integrand_);
            error2 = std::abs(approx_sol2 - exact_sol);
            EOC = log(error1 / error2) / log(2);

            std::cout << "\tn = " << n << ", approximate solution = " << approx_sol2 << ", exact solution = " << exact_sol << std::endl;
            std::cout << "\tFor n = " << n/2 << " and 2n = " << n << ", EOC = " << EOC << std::endl << std::endl;
            error1 = error2;
        }
    }
};

#endif
