#include <gmpxx.h>
#include <gmp.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>

#include "utils.h"

mpz_class bound;
mpz_class root;
mpz_class min_bound;
int sieving_interval;

mpz_vector gen_factor_base(mpz_class N){
    mpz_vector ret;

    int count = 0;
    while(ret.size() < bound + min_bound){
        mpz_class prime = primes_under_x[count];
        if(mpz_legendre(N.get_mpz_t(), prime.get_mpz_t()) == 1){
            ret.push_back(prime);
        }
        count++;
    }

    return ret;
}

mpz_class get_optimal_fb_size_QS(mpz_class n){ // pow(exp(sqrt(log(N)*log(log(N)))),sqrt(2)/4)
    mpf_class a(n);
    double bound = a.get_d();
    bound = log(bound);//mpz_sizeinbase(n.get_mpz_t(), 3) - 1;   
    bound = bound*log(bound);
    bound = sqrt(bound);
    bound = exp(bound);        
    bound = pow(bound, sqrt(2)/4);        
    size_t tmp = (size_t)(bound+1);
    mpz_class ret(tmp);
    return ret;
}

mpz_class get_optimal_sieve_interval(mpz_class factor_base_size){
    mpz_class ret;
    mpz_pow_ui(ret.get_mpz_t(), factor_base_size.get_mpz_t(), 3);
    return ret;
}

mpz_class get_factor(bool_matrix sol_cands, mpz_vector smooth_nums, mpz_vector xs, mpz_class N){

    mpz_class factor;

    for(int i = 0; i < sol_cands.size(); i++){
        mpz_class a = 1;
        mpz_class b = 1;
        for(int j = 0; j < sol_cands[0].size(); j++){
            if(sol_cands[i][j] == 1){
                a = a * smooth_nums[j];
                b = b * xs[j]*xs[j]; 
            }
        }
        factor = gcd(sqrt(a)- sqrt(b), N);
        //std::cout << a << " " << b << " " << N << " " << gcd(b - sqrt(a), N) << std::endl; 
        if(factor != N && factor != 1) return factor;

    }
    return factor;
}


mpz_class quadratic_sieve(mpz_class N){
    bound = get_optimal_fb_size_QS(N);
    sieving_interval = get_optimal_sieve_interval(bound).get_ui();
    root = sqrt(N);
    mpz_vector factor_base = gen_factor_base(N);
    //print_vector(factor_base);

    mpz_vector sieving_seq;
    std::vector<std::pair<mpz_class, mpz_class>> tonelli_sols;
    std::vector<std::pair<mpz_class, mpz_class>> next_to_sieve;
    //std::cout << bound+min_bound << " " << sieving_interval << std::endl;


    // Generating sieving sequence of the form: Q(x) = x^2 - N
    mpz_class lower_bound = (root - sieving_interval);
    mpz_class upper_bound = (root + sieving_interval);

    for(mpz_class x = lower_bound; x <= upper_bound; x++){
        sieving_seq.push_back(x*x - N);
        //std::cout << "Q(" << x << ") = " << (x*x - N) << std::endl;
    }

    mpz_vector original_seq = sieving_seq;

    // Generating solutions to the equation s^2 ≡ N (mod p)
    bool two = false;
    if(factor_base[0] == 2){
        two = true;
        if(sieving_seq[0] % 2 == 0){
            tonelli_sols.push_back(std::make_pair(lower_bound, lower_bound));
        } else{
            tonelli_sols.push_back(std::make_pair(lower_bound+1, lower_bound+1));
        }
    }



    for(int i = 0+two; i < factor_base.size(); i++){
        mpz_class sol;
        mpz_sqrtm(sol.get_mpz_t(), N.get_mpz_t(), factor_base[i].get_mpz_t());
        tonelli_sols.push_back(std::make_pair(sol, factor_base[i]-sol));
    }


    //for(auto it : tonelli_sols) std::cout << it.first << std::endl;


    // Generating starting positions
    for(int i = 0; i < tonelli_sols.size(); i++){
        next_to_sieve.push_back(tonelli_sols[i]);
        mpz_class x;

        x = (lower_bound + next_to_sieve[i].first)/factor_base[i];
        next_to_sieve[i].first = next_to_sieve[i].first + x*factor_base[i];

        x = (lower_bound + next_to_sieve[i].second)/factor_base[i];
        next_to_sieve[i].second = next_to_sieve[i].second + x*factor_base[i];
        

    }

/*     for(auto it : tonelli_sols) std::cout << it.first << " " << it.second << std::endl;
    std::cout << std::endl;
    for(auto it : next_to_sieve) std::cout << it.first << " " << it.second << std::endl;
    std::cout << std::endl; */
    bool_matrix exp_matrix_unfiltered(sieving_seq.size(), bool_vector(factor_base.size()+1, 0));
    //print_matrix(exp_matrix_unfiltered);

    // Sieving step
    for(int i = 0; i < next_to_sieve.size(); i++){
        while(next_to_sieve[i].first <= upper_bound){
            mpz_class tmp = next_to_sieve[i].first - lower_bound;
            long long index = tmp.get_ui();
            //std::cout << sieving_seq[index] << " " << factor_base[i]<<  std::endl;
            while(sieving_seq[index] % factor_base[i] == 0){
                exp_matrix_unfiltered[index][i+1] = !exp_matrix_unfiltered[index][i+1];
                sieving_seq[index] = sieving_seq[index] / factor_base[i];
            }
            next_to_sieve[i].first += factor_base[i];
        }
        while(next_to_sieve[i].second <= upper_bound){
            mpz_class tmp = next_to_sieve[i].second - lower_bound;
            long long index = tmp.get_ui();
            while(sieving_seq[index] % factor_base[i] == 0){
                exp_matrix_unfiltered[index][i+1] = !exp_matrix_unfiltered[index][i+1];
                sieving_seq[index] = sieving_seq[index] / factor_base[i];
            }
            next_to_sieve[i].second+= factor_base[i];
        }
    }

    //print_vector(sieving_seq);


    for(int i = 0; i < sieving_seq.size(); i++){
        if(sieving_seq[i] < 0){
            exp_matrix_unfiltered[i][0] = true;
            sieving_seq[i] = sieving_seq[i] * (-1);
        }
    }

    bool_matrix exp_matrix_filtered;
    mpz_vector smooth_nums;
    mpz_vector xs;

    for(int i = 0; i < sieving_seq.size(); i++){
        if(sieving_seq[i] == 1){
            smooth_nums.push_back(original_seq[i]);
            xs.push_back(i+lower_bound);
            exp_matrix_filtered.push_back(exp_matrix_unfiltered[i]);
        }
    }

    //print_vector(smooth_nums);


    //std::cout << "exp_matrix_filtered.size(): " << exp_matrix_filtered.size() << std::endl;
    //print_matrix(exp_matrix_filtered);
    //std::cout << "exp_matrix_filtered[0].size(): " << exp_matrix_filtered[0].size() << std::endl;


    bool_matrix cand_sols = gaussElim(exp_matrix_filtered);
    //std::cout << "cand_sols: " << cand_sols.size() << std::endl;

    //print_matrix(cand_sols);



    return get_factor(cand_sols, smooth_nums, xs, N);

}