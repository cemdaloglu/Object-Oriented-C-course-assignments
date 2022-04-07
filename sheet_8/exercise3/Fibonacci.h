#ifndef OOPFSC2122_FIBONACCI_H
#define OOPFSC2122_FIBONACCI_H

constexpr int fib(int n){
    return n == 1 || n == 0 ? 1: fib(n-1) + fib(n-2);
}

#endif
