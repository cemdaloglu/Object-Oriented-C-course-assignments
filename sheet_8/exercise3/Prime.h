#ifndef OOPFSC2122_PRIME_H
#define OOPFSC2122_PRIME_H
#include <type_traits>

constexpr bool is_prime(int p, int k){
    return k == 1? true : p % k !=0 ? is_prime(p,k-1) : false;
}

constexpr bool is_prime(int p){
    return is_prime(p, p-1);
}

constexpr int next_prime(int n){
    return is_prime(n+1)? n+1 : next_prime(n+1);
}

constexpr int prime(int n){
    return n == 1 ? 2 : next_prime(prime(n-1));
}

#endif
