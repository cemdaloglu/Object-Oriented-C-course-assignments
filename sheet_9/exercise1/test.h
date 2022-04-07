#ifndef SOLUTIONS_TEST_H
#define SOLUTIONS_TEST_H
#include<cmath>

template<typename T, class I>
class Test
{
    T exact_sol;
    int n;
    I integral;
public:

    Test(I &integral, int n_, T exact_sol_) :
            exact_sol{exact_sol_},
            n{n_},
            integral{integral}
    {}

    void show()
    {
        T approx_sol1, approx_sol2, error1, error2, EOC;
        approx_sol1 = integral.rule1(n, integral.limits_, integral.composite_rule1, integral.integrand_);
        error1 = std::abs(approx_sol1 - exact_sol);
        std::cout << "\tn = " << n <<", approximate solution = " << approx_sol1 << ", exact solution = "<< exact_sol << std::endl;
        int limit = 1000;
        while(n <= limit)
        {
            n = 2 * n;
            approx_sol2 = integral.rule1(n, integral.limits_, integral.composite_rule1, integral.integrand_);
            error2 = std::abs(approx_sol2 - exact_sol);
            EOC = log(error1 / error2) / log(2);

            std::cout << "\tn = " << n << ", approximate solution = " << approx_sol2 << ", exact solution = " << exact_sol << std::endl;
            std::cout << "\tFor n = " << n/2 << " and 2n = " << n << ", EOC = " << EOC << std::endl << std::endl;
            error1 = error2;
        }
    }
};

#endif
