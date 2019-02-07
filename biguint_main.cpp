#include "biguint.h"

int main(){
    biguint a("123");
    biguint b("23");
    std::cout << a>b << endl;
    std::cout << a<b << endl;
    std::cout << a<=b << endl;
    std::cout << a>=b << endl;
    std::cout << a==b << endl;
    std::cout << a!=b << endl;
    return 0;
}