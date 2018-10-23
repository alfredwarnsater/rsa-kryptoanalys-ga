#include <gmpxx.h>
#include <gmp.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

#include "utils.h"

typedef std::vector<int> int_vector;
typedef std::vector<bool> bool_vector;
typedef std::vector<int_vector> matrix;
typedef std::vector<mpz_class> mpz_vector;
typedef std::pair<int_vector, bool> vb_pair;

int_vector sieve_of_eratosthenes(int n){
    bool_vector a(n+1, true);
    int_vector primes;
    for(size_t i = 2; i <= sqrt(n); i++){
        if(a[i]){
            for(size_t j = i*i; j <= n; j+=i){
                a[j] = false;
            }
        }
    }

    for(size_t i = 2; i <= n; i++){
        if(a[i]) primes.push_back(i);
    }
    
    return primes;
}

vb_pair factor_smooth(mpz_class n, const int_vector &factor_base, const int &factor_base_size){
    int_vector factors(factor_base_size, 0);
    vb_pair r;
    for(size_t i=0; i < factor_base_size; i++) {
        while (n % factor_base[i] == 0) {
            n = n / factor_base[i];
            factors[i]++;
        }
    }

    r.first = factors;

    if(n != 1) r.second = false;
    else r.second = true;

    return r;
}

mpz_vector dixons(mpz_class n){

    int factor_base_size = 5;
    int_vector factor_base = sieve_of_eratosthenes(factor_base_size);
    factor_base_size = factor_base.size();

    int i = 0;
    mpz_class z;
    while(i < factor_base_size + 1){
        z = get_random_number(n);
        mpz_class z_squared_mod_n = z*z % n;
        vb_pair fs = factor_smooth(z_squared_mod_n, factor_base, factor_base_size);
        

    } 


    mpz_vector ret;
    return ret;

}

int main(){
    mpz_class random_upper_bound("123125837512873");
    mpz_class arandom = get_random_number(random_upper_bound);

    std::cout << arandom << std::endl;
    mpz_class testing_number("1000");

    dixons(testing_number);
    
    return 0;
}