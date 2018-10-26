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

int x = 100000000;
int_vector primes_under_x = sieve_of_eratosthenes(x);



int tonelli(mpz_t x, mpz_t q, mpz_t n)
{
    int                        leg;
    mpz_t                        tmp,ofac,nr,t,r,c,b;
    unsigned int            mod4;
    mp_bitcnt_t                twofac=0,m,i,ix;

    mod4=mpz_tstbit(n,0);
    if(!mod4) // must be odd
        return 0;

    mod4+=2*mpz_tstbit(n,1);

    leg=mpz_legendre(q,n);
    if(leg!=1)
        return leg;

    mpz_init_set(tmp,n);

    if(mod4==3) // directly, x = q^(n+1)/4 mod n
        {
        mpz_add_ui(tmp,tmp,1UL);
        mpz_tdiv_q_2exp(tmp,tmp,2);
        mpz_powm(x,q,tmp,n);
        mpz_clear(tmp);
        }
    else // Tonelli-Shanks
        {
        mpz_inits(ofac,t,r,c,b,NULL);

        // split n - 1 into odd number times power of 2 ofac*2^twofac
        mpz_sub_ui(tmp,tmp,1UL);
        twofac=mpz_scan1(tmp,twofac); // largest power of 2 divisor
        if(twofac)
            mpz_tdiv_q_2exp(ofac,tmp,twofac); // shift right

        // look for non-residue
        mpz_init_set_ui(nr,2UL);
        while(mpz_legendre(nr,n)!=-1)
            mpz_add_ui(nr,nr,1UL);

        mpz_powm(c,nr,ofac,n); // c = nr^ofac mod n

        mpz_add_ui(tmp,ofac,1UL);
        mpz_tdiv_q_2exp(tmp,tmp,1);
        mpz_powm(r,q,tmp,n); // r = q^(ofac+1)/2 mod n

        mpz_powm(t,q,ofac,n);
        mpz_mod(t,t,n); // t = q^ofac mod n

        if(mpz_cmp_ui(t,1UL)!=0) // if t = 1 mod n we're done
            {
            m=twofac;
            do
                {
                i=2;
                ix=1;
                while(ix<m)
                    {
                    // find lowest 0 < ix < m | t^2^ix = 1 mod n
                    mpz_powm_ui(tmp,t,i,n); // repeatedly square t
                    if(mpz_cmp_ui(tmp,1UL)==0)
                        break;
                    i<<=1; // i = 2, 4, 8, ...
                    ix++; // ix is log2 i
                    }
                mpz_powm_ui(b,c,1<<(m-ix-1),n); // b = c^2^(m-ix-1) mod n
                mpz_mul(r,r,b);
                mpz_mod(r,r,n); // r = r*b mod n
                mpz_mul(c,b,b);
                mpz_mod(c,c,n); // c = b^2 mod n
                mpz_mul(t,t,c);
                mpz_mod(t,t,n); // t = t b^2 mod n
                m=ix;
                }while(mpz_cmp_ui(t,1UL)!=0); // while t mod n != 1
            }
        mpz_set(x,r);
        mpz_clears(tmp,ofac,nr,t,r,c,b,NULL);
        }

    return 1;
}

mpz_pair tonelli_both_sol(mpz_class n, mpz_class p){
    mpz_pair ret;
    mpz_class ret1;
    mpz_class ret2;
    tonelli(ret1.get_mpz_t(), n.get_mpz_t(), p.get_mpz_t());

    ret.first = ret1;
    mpz_neg(ret2.get_mpz_t(), ret1.get_mpz_t());
    mpz_mod(ret2.get_mpz_t(), ret2.get_mpz_t(), p.get_mpz_t());
    ret.second = ret2;

    return ret;
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



