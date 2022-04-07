#ifndef Q2_HH
#define Q2_HH
#include <iostream>

class Rational{
  public:
    Rational() : P(1), Q(1) {} 
    Rational(int p): P(p), Q(1) {}

    Rational(int p, int q){
      if(q ==0){
        throw std::invalid_argument( "division by zero");
      }
      int g = gcd(p,q);
      P =  p/g;
      Q =  q/g;
    }

    Rational& operator+=(const Rational r);
    Rational& operator*=(const Rational r);
    Rational& operator-=(const Rational r);
    Rational& operator/=(const Rational r);
    bool operator==(const Rational r);
    friend std::ostream& operator<<(std::ostream& os, const Rational& s);

    int numerator(){
      return P;
    }

    int denominator(){
      return Q;
    }
    
    void print();

  int gcd(int a, int b);

  private:
  int P;
  int Q;
};
Rational operator+(Rational b, Rational r);
Rational operator*(Rational b, Rational r);
Rational operator-(Rational b, Rational r);
Rational operator/(Rational b, Rational r);
#endif