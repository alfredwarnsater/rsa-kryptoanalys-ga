#include "trial_divison.h"
#include "fermat_factor.h"
#include "rsa_nums_200.h"
#include "dixons.h"
#include <gmpxx.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
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
    init_random();  

    mpz_class b("143");
    dixons(b);





/*     for(int i = 0; i < 90; i++){
        mpz_class b(rsa_nums[i][2]);
        long long beforeTime = getTime();
        
        long long afterTime = getTime();
        cout << 10+i << "\t" << (afterTime - beforeTime) / 1000.0 << endl; 
    } */

}