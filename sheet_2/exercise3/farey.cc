//
// Created by Niklas Wünstel on 05.11.21.
//
#include "q_2.hh"
#include "list"
#include "ostream"
#include "farey.h"

void Farey(int N){
    if(N <=0){
        throw std::invalid_argument("N must be > 0");
    }
    Rational a(0), b(1);
    std::list<Rational> sequence{a, b};
    print_sequence(1, sequence);
    for(int i = 2; i <= N; ++i){
        farey_up(sequence, i);
        print_sequence(i,sequence);
    }
}

void farey_up(std::list<Rational>& seq, int N){
    std::list<Rational>::iterator before = seq.begin();
    for(std::list<Rational>::iterator iter = ++seq.begin(); iter != seq.end(); ++iter){
        if(before->denominator() + iter->denominator() == N){
            Rational r(before->numerator() + iter->numerator(), before->denominator() + iter->denominator());
            seq.insert(iter, r);
        }
        before = iter;
    }
}

void print_sequence(int N, std::list<Rational> seq){
    std::cout <<"F"<< N<<  "=(";
    int i = 0;
    for(Rational &r: seq){
        if (i == 1){
            std::cout << ",";
        }
        else{
            ++i;
        }
        std::cout << r.numerator() << "/" << r.denominator();
    }
    std::cout << ")"<<std::endl;
}
