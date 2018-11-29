/**
 * http://en.cppreference.com/w/cpp/language/operator_precedence
 */

#include <iostream>
using namespace std;

class Foo {
  int i;
public:
  Foo():i(0){}
  void test() {
    cout << "i = " << i++;
  }
};
