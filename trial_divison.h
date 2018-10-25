
mpz_class trial_division(mpz_class n){
    mpz_class factor("1");
    mpz_class f = 3;
    while(f*f <= n){
        if(n % f == 0){
            return f;
            n = n / f;
        } else {
            f = f + 2;
        }
    }
    return factor;
}