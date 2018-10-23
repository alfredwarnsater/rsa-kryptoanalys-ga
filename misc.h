#include <gmpxx.h>
#include <vector>

typedef std::vector<int> int_vector;
typedef std::vector<int_vector> matrix;
typedef std::vector<mpz_class> mpz_vector;



template <typename T> // Takes int_vector or mpz_vector
void print_vector(const T &x)
{
    for(size_t i=0; i<x.size(); i++)
        std::cout << x[i] << ", ";

    std::cout << '\n';
}

mpz_class randomPrime(int b, int seed){
    b = b - 2;
    gmp_randstate_t rs;
    gmp_randinit_default(rs);
    gmp_randseed_ui(rs, seed);
    mpz_t random;
    mpz_init(random);
    mpz_class high = pow(2, b);
    mpz_class low = pow(2, b+1);
    mpz_class tmp = high-low;
    mpz_urandomm(random, rs, tmp.get_mpz_t());
    mpz_class tmp2(random);
    mpz_class ret = tmp2+low;
    mpz_nextprime(ret.get_mpz_t(), ret.get_mpz_t());
    return ret;
    
}