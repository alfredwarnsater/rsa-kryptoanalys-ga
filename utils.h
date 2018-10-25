#pragma once

#include <gmpxx.h>
#include <chrono>

typedef std::vector<int> int_vector;
typedef std::vector<bool> bool_vector;
typedef std::vector<int_vector> int_matrix;
typedef std::vector<mpz_class> mpz_vector;
typedef std::pair<int_vector, bool> vb_pair;

using namespace std::chrono;

template <typename T> // Takes int_vector or mpz_vector
void print_vector(const T &x)
{
    for(size_t i=0; i<x.size(); i++)
        std::cout << x[i] << ", ";

    std::cout << '\n';
}

void print_matrix(int_matrix im)
{
    for(auto it : im){
        for(auto it2 : it){
            std::cout << it2 << " ";
        }
        std::cout << "\n";
    }
}


long long getTime(){
    return duration_cast< milliseconds >(
    system_clock::now().time_since_epoch()
    ).count();
}

int BAD = 13764871;
gmp_randstate_t rs;

void init_random(){
    gmp_randinit_default(rs);
    gmp_randseed_ui(rs, BAD);
}

mpz_class get_random_number(mpz_class random_upper_bound){
    mpz_t random;
    mpz_init(random);
    mpz_urandomm(random, rs, random_upper_bound.get_mpz_t());
    mpz_class ret(random);
    return ret;
}

int_matrix matrix_mod2(int_matrix matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = matrix[i][j] % 2;
        }
    }

    return matrix;


}

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

mpz_class factor;

int_matrix gaussElim(int_matrix matrix){
        
        matrix = matrix_mod2(matrix);
        int n = matrix.size();
        int m = matrix[0].size();
        int i, j, k, l, freeCount, solutionCount;

        bool_vector marks(n, 0);
        int markCount = 0;
        for(j = 0; j < m; j++){
            for(i = 0; i < n; i++){
                if(matrix[i][j] == 1){
                    marks[i] = true;
                    markCount++;
                    for(k = 0; k < m; k++){
                        if(matrix[i][k] == 1 && k != j){
                            for(l = 0; l < n; l++){
                                matrix[l][k] = (matrix[l][k] + matrix[l][j])%2;
                            }
                        }
                    }
                    break;
                }
            }
        }

        freeCount = n - markCount;

        std::vector<std::vector<int>> ret(freeCount, std::vector<int>(n));
        solutionCount = 0;
        for(i = 0; i < n; i++){
            if(!marks[i]){
                ret[solutionCount][i] = 1;
                for(j = 0; j < m; j++){
                    if(matrix[i][j] == 1){
                        for(l = 0; l < n; l++){
                            if(matrix[l][j] == 1 && marks[l]){
                                ret[solutionCount][l] = 1;
                            }
                        }
                    }
                }
                solutionCount++;
            }
        }
        
        return ret;

    }



