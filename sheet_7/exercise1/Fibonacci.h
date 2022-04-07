//
// Created by Niklas Wünstel on 12.12.21.
//

#ifndef OOPFSC2122_FIBONACCI_H
#define OOPFSC2122_FIBONACCI_H

template<int n>
class Fibonacci {
public:
    static const int value = Fibonacci<n-1>::value + Fibonacci<n-2>::value;
};

template<>
class Fibonacci<1> {
public:
    static const int value = 1;
};

template<>
class Fibonacci<0> {
public:
    static const int value = 1;
};

int fib(int n){
    if(n == 0 || n== 1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }

}


#endif //OOPFSC2122_FIBONACCI_H

