#include "rational_numbers.hpp"
#include<iostream>

int Rational::gcd(int num_1, int num_2) {
    if (num_2 == 0)
        return num_1;
    return gcd(num_2, num_1 % num_2);
}

Rational &Rational::operator*=(const Rational& x) {
    int n = num * x.num;
    int d = denom * x.denom;
    int out = gcd(n, d);
    num = n / out;
    denom = d / out;
    return *this;
}

Rational &Rational::operator/=(const Rational& x) {
    if (x.num == 0){
        throw std::invalid_argument("invalid arg");
    }
    int n = num * x.denom;
    int d = denom * x.num;
    int out = gcd(n, d);
    num = n / out;
    denom = d / out;
    return *this;
}

Rational &Rational::operator+=(const Rational& x) {
    int n = num * x.denom + x.num * denom;
    int d = denom * x.denom;
    int out = gcd(n, d);
    num = n / out;
    denom = d / out;
    return *this;
}

Rational &Rational::operator-=(const Rational& x) {
    int n = num * x.denom - x.num * denom;
    int d = denom * x.denom;
    int out = gcd(n, d);
    num = n / out;
    denom = d / out;
    return *this;
}

void Rational::print() const{
    std::cout << this;
}

bool Rational::operator==(const Rational &x) {
    return num == x.num && denom == x.denom;
}

std::ostream &operator<<(std::ostream &out, const Rational &x) {
    out << x.num << "/" << x.denom;
    return out;
}

Rational& operator+(Rational a, Rational b){
    return a += b;
}

Rational& operator-(Rational a, Rational b){
    return a -= b;
}

Rational& operator*(Rational a, Rational b){
    return a *= b;
}

Rational& operator/(Rational a, Rational b){
    return a /= b;
}
