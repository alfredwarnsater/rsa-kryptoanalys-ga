#include <gmpxx.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

// Constants
// The optimal smoothness bound is exp((0.5 + o(1)) * sqrt(log(n)*log(log(n)))).
const int SMOOTH_BOUND = 500;
const int TRIAL_BOUND = 400;
const int SIEVE_CHUNK = 60;

const bool DEBUG = false;

void *_Unwind_Resume;
void *__gxx_personality_v0;


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