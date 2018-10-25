#include <gmpxx.h>
#include <gmp.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

#include "utils.h"



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


int x = 100000000;
int_vector primes_under_x = sieve_of_eratosthenes(x);

int_vector generate_primes(int number_of_primes){

    int_vector ret;
    for(int i = 0; i < number_of_primes; i++){
        ret.push_back(primes_under_x[i]);
    }

    return ret;
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

mpz_class n("143");

size_t get_optimal_fb_size(mpz_class n){
    double bound = mpz_sizeinbase(n.get_mpz_t(), 10) - 1; 
    bound = bound*log10(bound);
    bound = sqrt(bound);
    bound = exp(bound);
    size_t ret = (size_t)(bound+1);
    return ret;
}

mpz_class get_factors(int_matrix solutions, const int_vector &factor_base, const mpz_vector &right, const mpz_vector &left){
    int solution_count = solutions.size();
    mpz_class a, b;
    a = 1;
    b = 1;
    for(int i = 0; i < solution_count; i++){
        for(int j = 0; j < factor_base.size(); j++){
            if(solutions[i][j]){
                a = a * left[j];
                b = b * right[j];
            }
        }
        std::cout << gcd(sqrt(a)-sqrt(b), n)  << " " << gcd(sqrt(a)+sqrt(b), n) << std::endl;
    }

    

}

mpz_vector dixons(mpz_class n){

    size_t optimal_fb_size = 4*get_optimal_fb_size(n);
    //std::cout << "optimal_fb_size " << optimal_fb_size << std::endl;

    int_vector factor_base = generate_primes(optimal_fb_size);
    
    int factor_base_size = factor_base.size();
    //std::cout << "factor_base_size: " << factor_base_size << std::endl << "factor_base: ";
    //print_vector(factor_base);

    int i = 0;
    mpz_class z, z_squared, z_squared_mod_n;
    mpz_vector left;
    mpz_vector right;
    int_matrix right_exp;

    while(i < factor_base_size + 1){
        z = get_random_number(n);
        z_squared = z*z;
        z_squared_mod_n = z_squared % n;
        vb_pair fs = factor_smooth(z_squared_mod_n, factor_base, factor_base_size);
        if(fs.second){
            left.push_back(z_squared);
            right.push_back(z_squared_mod_n);
            right_exp.push_back(fs.first);
            i++;
        }
    }

    int_matrix solutions = gaussElim(right_exp);
/*     print_vector(left);
    print_vector(right);
    print_matrix(solutions); */
    get_factors(solutions, factor_base, right, left);


    mpz_vector ret;
    return ret;

}