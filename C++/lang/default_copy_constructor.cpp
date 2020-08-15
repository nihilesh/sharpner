#include <iostream>
#include <string>

using namespace std;

class Bar {
public:
  Bar(int bar): bar(bar){}
  void print(){
    cout << "Bar: " << bar << endl;
  }
private:
  int bar;

};

class Foo {
public:
  int foo;
  Bar* bar;
  Foo(int foo): foo(foo) {
    bar = new Bar(foo);
  }
  ~Foo() {
    cout << "Destroying Foo " << endl;
    delete bar;
  }
};

int main() {
  Foo f(5);
  f.bar->print();
  Foo f1(f);
  return 0;
}
