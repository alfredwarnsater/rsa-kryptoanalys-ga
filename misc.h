#include <vector>
#include <gmpxx.h>

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

mpz_class randomPrime(int b){
    
}