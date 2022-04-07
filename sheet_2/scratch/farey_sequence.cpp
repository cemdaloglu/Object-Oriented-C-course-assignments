#include "rational_numbers.hpp"
#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;

bool cmp(Rational a, Rational b)
{
    return a.numerator() * b.denomirator() < b.numerator() * a.denomirator();
}

void Rational::Farey(int N) {
    vector<Rational> v{Rational(0), Rational(1)};
    int k = 1;
    int out;
    int length = v.size()-1;
    Rational sum;
    for (int i = 0; i <= length; ++i) {
        sum = Rational(v[i].numerator() + v[i+1].numerator(), v[i].denomirator() + v[i+1].denomirator());
        out = gcd(sum.numerator(), sum.denomirator());
        if (out != 1)
            sum = (sum.numerator() / out) / (sum.denomirator() / out);
        if (sum.denomirator() == k+1)
            v.push_back(Rational(sum.numerator(), sum.denomirator()));

        if ((length - i) == 0) {
            k++;
            i = -1;
            sort(v.begin(), v.end(), cmp);
            length = v.size();
        }

        if (k==N){
            for (int i = 0; i < v.size(); ++i)
                cout << v[i].num << "/" << v[i].denom << " ";
            break;
        }
    }
}
