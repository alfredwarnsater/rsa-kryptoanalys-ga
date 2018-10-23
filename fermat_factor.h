#include <gmpxx.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include "misc.h"

mpz_vector fermat_factor(mpz_class n){
    mpz_vector factors;

    mpz_class a = sqrt(n-1)+1;
    mpz_class b_squared = a*a - n;

    while(!mpz_perfect_square_p(b_squared.get_mpz_t())){
        a = a + 1;
        b_squared = a*a - n;
        
    }

    factors.push_back(a - sqrt(b_squared));
    factors.push_back(a + sqrt(b_squared));
    return factors;
}