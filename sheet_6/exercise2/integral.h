#ifndef SOLUTIONS_INTEGRAL_H
#define SOLUTIONS_INTEGRAL_H
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

template<typename T>
class Function{
public:
    virtual T func_to_integrate(T x) = 0;
    virtual ~Function()= default;
};

template<typename T>
class Func1 : public Function<T>{
public:
    T func_to_integrate(T x) override{return 2*x + 5;}
};

template<typename T>
class Func2 : public Function<T>{
public:
    T func_to_integrate(T x) override{ return (x / M_PI * sin(x)); }
};


template<typename T, class F>
class Integrator {
public:
    Integrator(F integrand, Limits<T> limits){}
    virtual T rule(int step) = 0;
    virtual T composite_rule(T dx, Limits<T> limits_, int i) = 0;
};
#endif

template<typename T, class F>
class Trapez : public Integrator<T, F>{
public:
    Limits<T> limits_;
    F integrand_;

    Trapez(F integrand, Limits<T> limits) : Integrator<T, F>(integrand, limits){limits_ = limits; integrand_ = integrand;};

    T composite_rule(T dx, Limits<T> limits_, int i) override{
        T dy, dy2;
        dy = integrand_.func_to_integrate(limits_.lower + i * dx);
        dy2 = integrand_.func_to_integrate(limits_.lower + (i + 1) * dx);
        T area = dy + dy2;
        return area * dx / 2;
    }

    T rule(int stepSize) override{
        T dx;
        T distance = limits_.upper - limits_.lower;
        dx = distance / stepSize;

        T integral_ = 0;
        for (int i = 0; i < stepSize - 1; i++)
            integral_ += composite_rule(dx, limits_, i);
        return integral_;
    }
};

template<typename T, class F>
class Simpson : public Integrator<T, F>{
public:
    Limits<T> limits_;
    F integrand_;

    Simpson(F integrand, Limits<T> limits) : Integrator<T, F>(integrand, limits){limits_ = limits; integrand_ = integrand;};

    T composite_rule(T dx, Limits<T> limits_, int i) override{
        T dy, dy2, dy3;
        dy = integrand_.func_to_integrate(limits_.lower + i * dx);
        dy2 = integrand_.func_to_integrate(limits_.lower + (i + 1) * dx);
        dy3 = 4 * integrand_.func_to_integrate((limits_.lower + i * dx + limits_.lower + (i + 1) * dx) / 2);
        T area = dy + dy2 + dy3;
        return area * dx / 6;
    }

    T rule(int stepSize) override{
        T dx;
        T distance = limits_.upper - limits_.lower;
        dx = distance / stepSize;

        T integral_ = 0;
        for (auto i = 0; i < stepSize - 1; i++)
            integral_ += composite_rule(dx, limits_, i);
        return integral_;
    }
};