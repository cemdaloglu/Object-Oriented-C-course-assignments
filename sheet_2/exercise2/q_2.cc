#include "q_2.hh"
#include <iostream>

int Rational::gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

Rational& Rational::operator+=(const Rational r){
    int p = P*r.Q + r.P*Q;
    int q = Q*r.Q;
    int g = gcd(p,q);
    P = p/g;
    Q = q/g;
    return *this;
}

Rational& Rational::operator*=(const Rational r){
    int p = P*r.P;
    int q = Q*r.Q;
    int g = gcd(p,q);
    P = p/g;
    Q = q/g;
    return *this; 
}

Rational& Rational::operator-=(const Rational r){
    int p = P*r.Q - r.P*Q;
    int q = Q*r.Q;
    int g = gcd(p,q);
    P = p/g;
    Q = q/g;
    return *this;
}

Rational& Rational::operator/=(const Rational r){
    if(r.P ==0){
        throw std::invalid_argument( "division by zero");
    }
    int p = P*r.Q;
    int q = Q*r.P;
    int g = gcd(p,q);
    P = p/g;
    Q = q/g;
    return *this;
}

void Rational::print(){
    std::cout << this;
}

std::ostream& operator<<(std::ostream& os, const Rational& r){
    return os << r.P << "/" << r.Q << std::endl;
}

bool Rational::operator==(const Rational r){
    return P == r.P && Q == r.Q;
}

Rational operator*(Rational b, Rational r){
    Rational p(b);
    return p *= r;
}

Rational operator+(Rational b, Rational r){
    Rational p(b);
    return p += r;
}

Rational operator-(Rational b, Rational r){
    Rational p(b);
    return p -= r;
}

Rational operator/(Rational b, Rational r){
    Rational p(b);
    return p /= r;
}