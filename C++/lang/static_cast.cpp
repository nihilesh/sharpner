#include <iostream>
using namespace std;

void add_(unsigned int a, unsigned int b){
    unsigned int c = (unsigned int)((__uint128_t)(a+b) / 2);
    cout << "value is : " << c ;
}

void add(unsigned int a, unsigned int b){
    unsigned int c = (unsigned int)(((__uint128_t)a+ (__uint128_t)b) / 2);
    cout << "value is : " << c ;
}


int main() {
    add_(-1, -1);
    add(-1, -1);
}