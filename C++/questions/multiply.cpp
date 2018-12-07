#include <iostream>
#include <cstring>

using namespace std;

void print_array(int* arr, size_t n){
    int i = 0;
    while(i < n && arr[i] == 0) i++;
    for (; i < n ; i++) {
        cout << arr[i];
    }
}

void multiply(int* m, int mlen, int* n, int nlen){ // m, 5, n, 3
    int r[nlen][mlen+nlen+1]; // [3][9]
    memset(r, 0, sizeof(r));
    for (int i=nlen-1, kr=nlen-1; i>=0; i--, kr--){ // 5, 4, 3
        int kc = mlen+nlen; // 8
        for (int shift = nlen-1-i; shift; shift--){ // shift=3-1-2 
            r[kr][kc--] = 0;
        }
        int carry = 0;
        for (int j=mlen-1; j>=0; j--, kc--) { // 2, 6, 5, 4, 2
            int multi = n[i] * m[j] + carry;
            r[kr][kc] = multi % 10;
            carry = multi / 10;
            cout << "r[" << kr <<"][" << kc <<"] = " << r[kr][kc] << endl;  
        }
        if (carry) {
            r[kr][kc] = carry;
            cout << "r[" << kr <<"][" << kc <<"] = " << r[kr][kc] << endl;
        }
    } // [ 0, 2, 3, 4, 5, 6], [0, 0, 3, 4, 5, 0], [0, 0, 3, 4, 0, 0]
    int res[mlen+nlen+1];
    memset(res, 0, sizeof(res));
    int carry = 0;
    for (int i = mlen+nlen; i >=0; i--) {
        int sum = carry;
        for (int j=0; j < nlen; j++){
            sum += r[j][i];
        }
        res[i] = sum % 10;
        carry = sum / 10;
        cout << "res[" << i << "] = " << res[i] << endl;
    }
    print_array(m, mlen);
    cout << " * ";
    print_array(n, nlen);
    cout << " = ";
    print_array(res, mlen+nlen+1);
    cout <<  endl;
}

int main(){
    int m[5] = {2, 4, 5, 6, 2};
    int n[3] = {3, 4, 5};
    multiply(m, 5, n, 3);
    return 0;
}