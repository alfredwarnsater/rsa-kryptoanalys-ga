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

mpz_vector generate_sieve_seq(mpz_class n, mpz_class sieve_interval){
    mpz_vector sieve_seq;
    mpz_class root = sqrt(n);

    for(mpz_class x = root; x < root+sieve_interval; x++){
        sieve_seq.push_back(x*x - n);
    }
    return sieve_seq;
}

int_vector generate_factor_base(mpz_class n, mpz_class factor_base_size){
    int_vector factor_base;
    mpz_class prime;
    for(int i = 0; factor_base.size() < factor_base_size; i++){
        prime = primes_under_x[i];
        if(mpz_legendre(n.get_mpz_t(), prime.get_mpz_t()) == 1){
            factor_base.push_back(primes_under_x[i]);
        }
    }
    return factor_base;
}

void sieving_for_smooth(int_vector factor_base, mpz_class n, mpz_class sieve_interval){
    

}

mpz_class QS(mpz_class n){

    mpz_class factor_base_size = get_optimal_fb_size_QS(n);
    mpz_class sieve_interval = get_optimal_sieve_interval(factor_base_size);
    std::cout << "factor_base_size: " << factor_base_size << std::endl;
    std::cout << "sieve_interval: " << sieve_interval << std::endl;

    int_vector factor_base = generate_factor_base(n, factor_base_size);
    sieving_for_smooth(factor_base, n, sieve_interval);


    mpz_class asd("1");
    return asd;

}