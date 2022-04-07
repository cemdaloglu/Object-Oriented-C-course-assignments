#ifndef SOLUTIONS_LAMBDA_H
#define SOLUTIONS_LAMBDA_H
#include <algorithm>
#include <utility>
#include <cmath>
#include <functional>
#include <iostream>

template<typename T>
struct Limits {
    T lower;
    T upper;

    Limits(T a = 0., T b = 0.) :
            lower{ a < b ? a : b },
            upper{ a < b ? b : a }
    {}
};

#endif

template<typename T>
class Trapez{
public:
    std::function<T(T)> integrand_;
    Limits<T> limits_;
    Trapez(std::function<T(T)> integrand_, Limits<T> limits_) : integrand_{integrand_}, limits_{limits_} {}

    std::function<T(T, Limits<T>, int, std::function<T(T)>)> composite_rule1 = [](T dx, Limits<T> limits_, int i, std::function<T(T)> integrand_)
    {return (integrand_(limits_.lower + i * dx) + integrand_(limits_.lower + (i + 1) * dx)) * dx / 2;};


    std::function<T(int, Limits<T>, std::function<T(T, Limits<T>, int, std::function<T(T)>)>, std::function<T(T)>)> rule1 = [](int stepSize, Limits<T> limits_, std::function<T(T, Limits<T>, int, std::function<T(T)>)> composite_rule1, std::function<T(T)> integrand_){
        T dx;
        dx = (limits_.upper - limits_.lower) / stepSize;

        T integral_ = 0;
        for (int i = 0; i < stepSize - 1; i++)
            integral_ += composite_rule1(dx, limits_, i, integrand_);
        return integral_;};
};

template<typename T>
class Simpson{
public:
    Limits<T> limits_;
    std::function<T(T)> integrand_;

    Simpson(std::function<T(T)> integrand, Limits<T> limits) : integrand_{integrand}, limits_{limits} {}

    std::function<T(T, Limits<T>, int, std::function<T(T)>)> composite_rule1 = [](T dx, Limits<T> limits_, int i, std::function<T(T)> integrand_)
    {
        T dy, dy2, dy3;
        dy = integrand_(limits_.lower + i * dx);
        dy2 = integrand_(limits_.lower + (i + 1) * dx);
        dy3 = 4 * integrand_((limits_.lower + i * dx + limits_.lower + (i + 1) * dx) / 2);
        T area = dy + dy2 + dy3;
        return area * dx / 6;
    };

    std::function<T(int, Limits<T>, std::function<T(T, Limits<T>, int, std::function<T(T)>)>, std::function<T(T)>)> rule1 = []
            (int stepSize, Limits<T> limits_, std::function<T(T, Limits<T>, int, std::function<T(T)>)> composite_rule1, std::function<T(T)> integrand_) {
        T dx;
        T distance = limits_.upper - limits_.lower;
        dx = distance / stepSize;

        T integral_ = 0;
        for (auto i = 0; i < stepSize - 1; i++)
            integral_ += composite_rule(dx, limits_, i);
        return integral_;
    };
};
