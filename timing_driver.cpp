#include "trial_divison.h"
#include "fermat_factor.h"
#include "rsa_nums_200.h"
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

    std::cout << rsa_nums[190][2] << endl;

    for(int i = 0; i < 90; i++){
        mpz_class b(rsa_nums[i][2]);
        long long beforeTime = getTime();
        trial_division(b);
        long long afterTime = getTime();
        cout << 10+i << "\t" << (afterTime - beforeTime) / 1000.0 << endl; 
    }



}