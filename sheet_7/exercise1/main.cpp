//
// Created by Niklas Wünstel on 12.12.21.
//

#include <iostream>
#include "Fibonacci.h"
#include "Prime.h"
int main(){
    std::cout << "TMP Class: " << Fibonacci<INDEX>::value<< std::endl;
    std::cout << "Runtime Function: " << fib(INDEX) << std::endl;
    std::cout << INDEX << ". Prime number: " << prime<INDEX>::number << std::endl;
}

