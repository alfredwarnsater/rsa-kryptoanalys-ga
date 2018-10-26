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
#include "quadratic-sieve.h"

int main(int argc, char *argv[]){

    std::string inputnum = "122933";
    std::string algorithm_choice = "DIXON";
    if(argc >= 2) inputnum = argv[1];
    if(argc >= 3) algorithm_choice = argv[2];
    mpz_class n(inputnum);
    init_random();

    mpz_class factor;
    mpz_class a("38933443456562398");
    mpz_class b("415997014371920782955642881");

    long long beforeTime, afterTime;
    beforeTime = getTime();
    //mpz_pair mp = tonelli_both_sol(a, b);
    factor = QS(n);
    afterTime = getTime();
    //std::cout << (afterTime - beforeTime) / 1000.0 << " " << mp.first << " " << mp.second << std::endl;




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