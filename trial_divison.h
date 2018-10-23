#include <gmpxx.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

typedef std::vector<int> int_vector;
typedef std::vector<int_vector> matrix;
typedef std::vector<mpz_class> mpz_vector;

mpz_vector trial_division(mpz_class n){
    mpz_vector factors;
    while(n % 2 == 0){
        factors.push_back(2);
        n = n / 2;
    }
    mpz_class f = 3;
    while(f*f <= n){
        if(n % f == 0){
            factors.push_back(f);
            n = n / f;
        } else {
            f = f + 2;
        }
    }
    if(n != 1) factors.push_back(n);
    return factors;
}