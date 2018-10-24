#include <gmpxx.h>
#include <chrono>

template <typename T> // Takes int_vector or mpz_vector
void print_vector(const T &x)
{
    for(size_t i=0; i<x.size(); i++)
        std::cout << x[i] << ", ";

    std::cout << '\n';
}

using namespace std::chrono;
long long get_time_millis(){
    return duration_cast< milliseconds >(
    system_clock::now().time_since_epoch()
).count();
}

int BAD = 132764871;
gmp_randstate_t rs;

void init_random(){
    gmp_randinit_default(rs);
    gmp_randseed_ui(rs, BAD);
}

mpz_class get_random_number(mpz_class random_upper_bound){
    BAD++;
    mpz_t random;
    mpz_init(random);
    mpz_urandomm(random, rs, random_upper_bound.get_mpz_t());
    mpz_class ret(random);
    return ret;
}



