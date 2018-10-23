#include "trial_divison.h"
#include "fermat_factor.h"
#include <gmpxx.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include "misc.h"
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long getTime(){
    return duration_cast< milliseconds >(
    system_clock::now().time_since_epoch()
    ).count();
}

int main(){
    // 515951277762010710181 (70 bits)

    mpz_class b = randomPrime(38, 12318236)*randomPrime(38, 12312312);
    std::cout << b << std::endl;
    //std::string a;
    //std::cin >> a;
    //mpz_class b(a);

    long long beforeTime = getTime();
    mpz_vector abc = fermat_factor(b);
    long long afterTime = getTime();
    print_vector(abc);
    cout << (afterTime - beforeTime) / 1000.0 << endl; 


}