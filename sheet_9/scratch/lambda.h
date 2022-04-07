#ifndef SOLUTIONS_LAMBDA_H
#define SOLUTIONS_LAMBDA_H
#include <algorithm>
#include <utility>
#include <cmath>
#include <functional>
#include <iostream>

template<typename T>
struct Limits_lambda {
    T lower;
    T upper;

    Limits_lambda(T a = 0., T b = 0.) :
            lower{ a < b ? a : b },
            upper{ a < b ? b : a }
    {}
};


template<typename T>
std::function<T(int, Limits_lambda<T>, std::function<T(T, Limits_lambda<T>, int, std::function<T(T)>)>, std::function<T(T)>)> rule1 =
        [](int stepSize, Limits_lambda<T> limits_, std::function<T(T, Limits_lambda<T>, int, std::function<T(T)>)> composite_rule, std::function<T(T)> integrand_){
            T dx;
            dx = (limits_.upper - limits_.lower) / stepSize;

            T integral_ = 0;
            for (int i = 0; i < stepSize - 1; i++)
                integral_ += composite_rule(dx, limits_, i, integrand_);
            return integral_;};


template<typename T>
class Trapez_lambda{
public:
    std::function<T(T)> integrand_;
    Limits_lambda<T> limits_;
    Trapez_lambda(std::function<T(T)> &integrand_, Limits_lambda<T> limits_) : integrand_{integrand_}, limits_{limits_} {}

    std::function<T(T, Limits_lambda<T>, int, std::function<T(T)>)> composite_rule = [](T dx, Limits_lambda<T> limits_, int i, std::function<T(T)> integrand_)
    {return (integrand_(limits_.lower + i * dx) + integrand_(limits_.lower + (i + 1) * dx)) * dx / 2;};

};

template<typename T>
class Simpson_lambda{
public:
    Limits_lambda<T> limits_;
    std::function<T(T)> integrand_;

    Simpson_lambda(std::function<T(T)> integrand_, Limits_lambda<T> limits_) : integrand_{integrand_}, limits_{limits_} {}

    std::function<T(T, Limits_lambda<T>, int, std::function<T(T)>)> composite_rule = [](T dx, Limits_lambda<T> limits_, int i, std::function<T(T)> integrand_)
    {
        T dy, dy2, dy3;
        dy = integrand_(limits_.lower + i * dx);
        dy2 = integrand_(limits_.lower + (i + 1) * dx);
        dy3 = 4 * integrand_((limits_.lower + i * dx + limits_.lower + (i + 1) * dx) / 2);
        T area = dy + dy2 + dy3;
        return area * dx / 6;
    };
};
#endif