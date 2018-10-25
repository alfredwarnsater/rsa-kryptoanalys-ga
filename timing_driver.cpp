

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

int main(int argc, char *argv[]){

    std::string inputnum = "8603856411671";
    std::string algorithm_choice = "DIXON";
    if(argc >= 2) inputnum = argv[1];
    if(argc >= 3) algorithm_choice = argv[2];
    mpz_class n(inputnum);
    init_random();

    

    long long beforeTime, afterTime;

    if(algorithm_choice == "TRIAL"){
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


/*     for(int i = 0; i < 90; i++){
        mpz_class b(rsa_nums[i][2]);
        long long beforeTime = getTime();
        
        long long afterTime = getTime();
        cout << 10+i << "\t" << (afterTime - beforeTime) / 1000.0 << endl; 
    } */

}