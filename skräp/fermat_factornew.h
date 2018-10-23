
/*
void fermat_factornew(mpz_class n){
    mpz_t nnew, a, b_squared, tmp;
    mpz_init2(a, 200);
    mpz_init2(b_squared, 200);
    mpz_init2(tmp, 200);
    mpz_init_set(nnew, n.get_mpz_t());

    mpz_sub_ui(a, nnew, 1);
    mpz_sqrt(a, nnew);
    mpz_add_ui(a, a, 1);

    mpz_mul(b_squared, a, a);
    mpz_sub(b_squared, b_squared, nnew);


    mpz_t a = sqrt(n-1)+1;
    mpz_t b_squared = a*a - n;
    mpz_t tmp;



    mpz_t count;
    mpz_init(count);
    while(mpz_cmp(tmp, b_squared) != 0){       //!mpz_perfect_square_p(b_squared)
        mpz_add_ui(a, a, 1);
        mpz_mul(tmp, a, a);
        mpz_sub(b_squared, tmp, nnew);
        a = a + 1;
        tmp = a*a;
        b_squared = tmp - n;

        mpz_sqrt(tmp, b_squared);
        mpz_mul(tmp, tmp, tmp);
        
    }
    
    mpz_t tp;
    mpz_init(tp);
    mpz_sqrt(b_squared, b_squared);
    mpz_sub(tp, a, b_squared);
    std::cout << tp << " ";
    mpz_add(tp, a, b_squared);
    std::cout << tp << std::endl;
    
}
*/