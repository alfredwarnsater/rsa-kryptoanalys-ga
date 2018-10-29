#pragma once

#include <gmpxx.h>
#include <gmp.h>
#include <chrono>

typedef std::vector<int> int_vector;
typedef std::vector<bool> bool_vector;
typedef std::vector<int_vector> int_matrix;
typedef std::vector<mpz_class> mpz_vector;
typedef std::pair<int_vector, bool> vb_pair;
typedef std::pair<mpz_class, mpz_class> mpz_pair;

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

int x = 10000000;
int_vector primes_under_x = sieve_of_eratosthenes(x);


int mpz_sqrtm(mpz_t q, const mpz_t n, const mpz_t p) {
    mpz_t w, n_inv, y;
    unsigned int i, s;
      //TMP_DECL;
      //TMP_MARK;

      if(mpz_divisible_p(n, p)) {         /* Is n a multiple of p?            */
          mpz_set_ui(q, 0);               /* Yes, then the square root is 0.  */
          return 1;                       /* (special case, not caught        */
      }                                   /* otherwise)                       */
      /*if(mpz_legendre(n, p) != 1)         // Not a quadratic residue?         */
         /* return 0;                       // No, so return error              */
      if(mpz_tstbit(p, 1) == 1) {         /* p = 3 (mod 4) ?                  */
          mpz_set(q, p);
          mpz_add_ui(q, q, 1);
          mpz_fdiv_q_2exp(q, q, 2);
          mpz_powm(q, n, q, p);           /* q = n ^ ((p+1) / 4) (mod p)      */
          return 1;
      }
      //MPZ_TMP_INIT(y, 2*SIZ(p));
      //MPZ_TMP_INIT(w, 2*SIZ(p));
      //MPZ_TMP_INIT(n_inv, 2*SIZ(p));
      mpz_init(y);
      mpz_init(w);
      mpz_init(n_inv);

      mpz_set(q, p);
      mpz_sub_ui(q, q, 1);                /* q = p-1                          */
      s = 0;                              /* Factor out 2^s from q            */
      while(mpz_tstbit(q, s) == 0) s++;
      mpz_fdiv_q_2exp(q, q, s);           /* q = q / 2^s                      */
      mpz_set_ui(w, 2);                   /* Search for a non-residue mod p   */
      while(mpz_legendre(w, p) != -1)     /* by picking the first w such that */
          mpz_add_ui(w, w, 1);            /* (w/p) is -1                      */
      mpz_powm(w, w, q, p);               /* w = w^q (mod p)                  */
      mpz_add_ui(q, q, 1);
      mpz_fdiv_q_2exp(q, q, 1);           /* q = (q+1) / 2                    */
      mpz_powm(q, n, q, p);               /* q = n^q (mod p)                  */
      mpz_invert(n_inv, n, p);
      for(;;) {
          mpz_powm_ui(y, q, 2, p);        /* y = q^2 (mod p)                  */
          mpz_mul(y, y, n_inv);
          mpz_mod(y, y, p);               /* y = y * n^-1 (mod p)             */
          i = 0;
          while(mpz_cmp_ui(y, 1) != 0) {
              i++;
              mpz_powm_ui(y, y, 2, p);    /*  y = y ^ 2 (mod p)               */
          }
          if(i == 0) {                    /* q^2 * n^-1 = 1 (mod p), return   */
              //TMP_FREE;
        	  mpz_clear(w); mpz_clear(n_inv); mpz_clear(y);
              return 1;
          }
          if(s-i == 1) {                  /* In case the exponent to w is 1,  */
              mpz_mul(q, q, w);           /* Don't bother exponentiating      */
          } else {
              mpz_powm_ui(y, w, 1 << (s-i-1), p);
              mpz_mul(q, q, y);
          }
          mpz_mod(q, q, p);               /* r = r * w^(2^(s-i-1)) (mod p)    */
      }

      mpz_clear(w); mpz_clear(n_inv); mpz_clear(y);
      return 0;
}

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



