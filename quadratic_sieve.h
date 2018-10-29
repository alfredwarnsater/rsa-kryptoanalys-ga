#include <gmpxx.h>
#include <gmp.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

#include "utils.h"

mpz_class bound;
mpz_class root;
mpz_class min_bound = 200;
int sieving_chunk = 10;
int sieving_interval = 20;

mpz_vector gen_factor_base(mpz_class N){
    mpz_vector ret;

    int count = 0;
    while(primes_under_x[count] < bound + min_bound){
        mpz_class prime = primes_under_x[count];
        if(mpz_legendre(N.get_mpz_t(), prime.get_mpz_t()) == 1){
            ret.push_back(prime);
        }
        count++;
    }

    return ret;
}

mpz_class quadratic_sieve(mpz_class N){
    root = sqrt(N);
    bound = 0;
    mpz_vector factor_base = gen_factor_base(N);
    print_vector(factor_base);

    mpz_vector sieving_seq;
    std::vector<std::pair<mpz_class, mpz_class>> tonelli_sols;
    std::vector<std::pair<mpz_class, mpz_class>> next_to_sieve;

    //Generating sieving sequence
    mpz_class lower_bound = (root - sieving_interval);
    mpz_class upper_bound = (root + sieving_interval);

    for(mpz_class x = lower_bound; x <= upper_bound; x++){
        sieving_seq.push_back(x*x - N);
        std::cout << "Q(" << x << ") = " << (x*x - N) << std::endl;
    }


    if(sieving_seq[0] % 2 == 0){
        next_to_sieve.push_back(std::make_pair(lower_bound, lower_bound));
    } else{
        next_to_sieve.push_back(std::make_pair(lower_bound+1, lower_bound+1));
    }

    //Generating starting positions
    for(int i = 1; i < factor_base.size(); i++){
        mpz_class sol;
        mpz_sqrtm(sol.get_mpz_t(), N.get_mpz_t(), factor_base[i].get_mpz_t());
        tonelli_sols.push_back(std::make_pair(sol, factor_base[i]-sol));
    }

    for(int i = 1; i < tonelli_sols.size(); i++){
        next_to_sieve.push_back(tonelli_sols[i-1]);
        while(next_to_sieve[i].first - factor_base[i] >= lower_bound){
            next_to_sieve[i].first = next_to_sieve[i].first - factor_base[i];
        }
    }

    for(auto it : factor_base)    std::cout << it << std::endl;
    std::cout <<  std::endl;
    for(auto it : tonelli_sols)    std::cout << it.first << std::endl;
    std::cout <<  std::endl;
    for(auto it : next_to_sieve)    std::cout << it.first << std::endl;








    //for(auto it : sieving_seq)    std::cout << it << std::endl;

    //for(auto it : tornelli_sols)    std::cout << "Solution"  << " " << it.first << " " << it.second << std::endl;



}