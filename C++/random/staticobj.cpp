#include <iostream>
using namespace std;

class Foo;

class Foo {
public :
  Foo() {
    cout << "Inside constructor Foo()" << endl;
  }
  Foo( string s) {
    cout << "Inside constructor Foo(" << s << ")" << endl;
    name = s;
  }
  ~Foo() {
    cout << "Destructor of ~Foo( "<< name << ") called" << endl;
  }
private:
  string name;
};

static Foo f;
static Foo f1("Atul");

void fun() {
  static Foo s("funcstatic");
}

int main ( int argc, char **argv) {
  Foo f3("Patil");
  fun();
  fun();
  return 0;
}

