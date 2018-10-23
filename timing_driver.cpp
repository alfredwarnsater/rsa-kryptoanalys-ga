#include "trial_divison.h"
#include "fermat_factor.h"

int main(){
    
    std::string a;
    std::cin >> a;
    mpz_class b(a);


    //print_vector(trial_division(b));
    print_vector(fermat_factor(b));

}