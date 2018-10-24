#include <gmpxx.h>
#include <gmp.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

#include "utils.h"

typedef std::vector<int> int_vector;
typedef std::vector<bool> bool_vector;
typedef std::vector<int_vector> int_matrix;
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

size_t get_optimal_fb_size(mpz_class n){
    double bound = mpz_sizeinbase(n.get_mpz_t(), 10) - 1; 
    bound = bound*log10(bound);
    bound = sqrt(bound);
    bound = exp(bound);
    size_t ret = (size_t)(bound+1);
    return ret;
}

mpz_vector dixons(mpz_class n){

    size_t optimal_fb_size = get_optimal_fb_size(n)*4;
    std::cout << "optimal_fb_size " << optimal_fb_size << std::endl;

    int_vector factor_base = generate_primes(optimal_fb_size);
    
    int factor_base_size = factor_base.size();
    std::cout << "factor_base_size: " << factor_base_size << std::endl << "factor_base: ";
    print_vector(factor_base);

    int i = 0;
    mpz_class z, z_squared, z_squared_mod_n;
    mpz_vector left;
    int_matrix right;

    while(i < factor_base_size + 1){
        z = get_random_number(n);
        //std::cout << z << std::endl;
        z_squared = z*z;
        z_squared_mod_n = z_squared % n;
        vb_pair fs = factor_smooth(z_squared_mod_n, factor_base, factor_base_size);
        if(fs.second){
            left.push_back(z_squared);
            right.push_back(fs.first);
            i++;
            //std::cout << i << std::endl;
        }
    }

    print_vector(left);


    mpz_vector ret;
    return ret;

}

int main(){


    init_random();
    mpz_class testing_number("27281976717628902959");
    long long bt = get_time_millis();
    std::cout << bt << std::endl;
    dixons(testing_number);
    long long at = get_time_millis();



    std::cout << (at - bt) / 1000.0 << std::endl;    
    return 0;
}