#include "test.h"
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
    
    

    long long beforeTime = getTime();
    start_qs();
    long long afterTime = getTime();
    cout << (afterTime - beforeTime) / 1000.0 << endl;

}