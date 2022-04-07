#ifndef SHEET2_TRIAL_RATIONAL_NUMBERS_HPP
#define SHEET2_TRIAL_RATIONAL_NUMBERS_HPP

#include<iostream>

class Rational
{
public:
    static int gcd(int num_1, int num_2);
    int numerator(){
        return num;
    }
    int denomirator(){
        return denom;
    }
    Rational() : num(1), denom(1) {};
    Rational(int given_num, int given_denom){
        if (given_denom == 0){
            throw std::invalid_argument("invalid arg");
        }
        int out = gcd(given_num, given_denom);
        num = given_num / out;
        denom = given_denom / out;
    };
    Rational(int whole_num) : num(whole_num), denom(1) {};

    Rational& operator*=(const Rational& x);
    Rational& operator+=(const Rational& x);
    Rational& operator-=(const Rational& x);
    Rational& operator/=(const Rational& x);
    bool operator==(const Rational& x);

    void print() const;
    static void Farey(int N);

    friend std::ostream & operator << (std::ostream &out, const Rational &x);
private:
    int num, denom;
};
Rational& operator+(Rational a, Rational b);
Rational& operator-(Rational a, Rational b);
Rational& operator*(Rational a, Rational b);
Rational& operator/(Rational a, Rational b);

#endif