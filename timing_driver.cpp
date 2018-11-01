#include <gmpxx.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

#include "trial_divison.h"
#include "fermat_factor.h"
#include "rsa_numbers/rsa_nums_200.h"
#include "dixons.h"
#include "quadratic_sieve.h"

int main(int argc, char *argv[]){

/*     std::string inputnum = "122933";
    std::string algorithm_choice = "DIXON";
    if(argc >= 2) inputnum = argv[1];
    if(argc >= 3) algorithm_choice = argv[2];
    mpz_class n(inputnum);
    init_random();

    mpz_class factor; */
    mpz_class a("143");
    mpz_class b("31");
    mpz_class c("1000000009");

    std::string input;
    std::cin >> input;

    mpz_class n(input);

    long long beforeTime, afterTime;
    beforeTime = getTime();
    mpz_class tmp = mpz_sqrtm(c.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
    //std::cout << c << std::endl;
    mpz_class factor = quadratic_sieve(n);
    std::cout << factor << std::endl;
    afterTime = getTime();
    std::cout << "Time: " << (afterTime - beforeTime) / 1000.0  << std::endl;




/*     if(algorithm_choice == "TRIAL"){
        beforeTime = getTime();
        factor = trial_division(n);
        afterTime = getTime();
    } else if(algorithm_choice == "FERMAT"){
        beforeTime = getTime();
        factor = fermat_factor(n);
        afterTime = getTime();
    } else if(algorithm_choice == "DIXON"){
        beforeTime = getTime();
        factor = dixons(n);
        afterTime = getTime();
    }

    // outputs time elapsed in seconds and the factors of n
    std::cout << (afterTime - beforeTime) / 1000.0 << " " << factor << " " << n/factor << std::endl;


    for(int i = 0; i < 90; i++){
        mpz_class b(rsa_nums[i][2]);
        beforeTime = getTime();
        fermat_factor(b);
        afterTime = getTime();
        std::cout << 10+i << "\t" << (afterTime - beforeTime) / 1000.0 << "\t";
        beforeTime = getTime();
        dixons(b);
        afterTime = getTime();
        std::cout << (afterTime - beforeTime) / 1000.0 << std::endl;

    }
 */
}