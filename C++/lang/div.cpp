#include <iostream>
using namespace std;
int main()
{
    cout << "-10/3 = " << (-10 / 3) << endl;
    long long l = -2;
    cout << "val = " << (unsigned long long)l<< endl;
    unsigned int a = (1 << 31) - 7;
    unsigned int b = (1 << 31) - 3;
    cout << "div= " << (int)((a * 3 + b * 7) / 10 ) << endl;
    }