//
// Created by Niklas Wünstel on 12.12.21.
//

#ifndef OOPFSC2122_PRIME_H
#define OOPFSC2122_PRIME_H

#include <type_traits>

template<int P, int K = P - 1>
struct is_prime {
    const static bool val = P % K != 0 && is_prime<P, K-1>::val;
};

template<int P>
struct is_prime<P, 1>{
    const static bool val = true;
};

//one is not prime
template<>
struct is_prime<1,1>{
    const static bool val= false;
};

template<int N, bool B = is_prime<N>::val>
struct next_prime{

};

template<int N>
struct next_prime<N,true>{
    const static int number = N;
};

template<int N>
struct next_prime<N, false>{
    const static int number = next_prime<N+1>::number;
};

template<>
struct next_prime<1,false>{
    const static int number = 2;
};

template<int N>
struct prime{
    const static int number = next_prime<prime<N-1>::number + 1>::number;
};

template<>
struct prime<1>{
    const static int number = 2;
};



#endif //OOPFSC2122_PRIME_H

