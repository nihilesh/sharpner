#include<iostream>
using namespace std;

void foo(string& s) { 
   s.append(" world");
}

int main() {
    string s1 = "hello";
    string s2(s1);
    s2.append(" world");
    cout << "S1:" << s1 << endl;
    cout << "S2:" << s2 << endl;
    foo(s1);
    cout << "S1:" << s1 << endl;
    string& s3 = s1;
    s3.erase(s3.begin() + s3.find(" world"), s3.end());
    cout << "S1:" << s1 << endl;
    cout << "S3:" << s3 << endl;
    return 0;
}