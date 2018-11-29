#include <iostream>
#include <stdlib.h>

namespace A {
  int i = 5;
  int foo() {
    std::cout << "A::foo()";
    return i;
  }
}

using namespace A;
namespace B {
  int j = 6;
  int bar() {
    // cout << "B::bar()" << endl; Using scope starts from where its first encountered
    std::cout << "B::bar()";
    return foo();
  }
  int foo() {
    std::cout << "B::foo()";
    //return foo(); //Gets resolved to current scope causing loop
    return ::foo(); //Gets resolved to root scope i.e. A 
  }    
}

using namespace std;
int main() {
  cout << "Hello World" << endl;
  cout << A::foo() << endl;
  cout << B::bar() << endl;
  
  cout << foo() << endl; //resolved to A as expected - namepsace using scope is additive
  cout << B::foo() << endl;

  using namespace B;
  //cout << foo() << endl; //Error ambiguous
  cout << B::foo() << endl;
}
