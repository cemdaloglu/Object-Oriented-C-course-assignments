#include <iostream>
#include <chrono>
#include "Fibonacci.h"
#include "Prime.h"

int main(){
    auto start = std::chrono::steady_clock::now();

    std::cout << "TMP Class: " << fib(40) << std::endl;

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    auto start2 = std::chrono::steady_clock::now();
    std::cout << 40 << ". Prime number: " << prime(40) << std::endl;
    auto end2 = std::chrono::steady_clock::now();

    auto diff2 = end2 - start2;
    std::cout << std::chrono::duration <double, std::milli> (diff2).count() << " ms" << std::endl;
}