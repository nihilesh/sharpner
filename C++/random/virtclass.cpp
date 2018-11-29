#include <iostream>
using namespace std;

class Base {
public:
  Base() { cout << "Base constructor" << endl; }
  virtual ~Base() { cout << "Base destructor" << endl; }

  int var() {
    cout << "Base::var()";
    return 10;
  }
  virtual int foo() = 0;
  virtual int bar() {
    cout << "Base::bar()";
    return 10;
  }
};

class Child: public Base {
public:
  Child() { cout << "Child constructor" << endl; }
  ~Child() { cout << "Child destructor" << endl; }

  virtual int var() {
    cout << "Child::var()";
    return 20;
  }
  virtual int foo() {
    cout << "Child::foo()";
    return 20;
  }
  int bar() {
    cout << "Child::bar()";
    return 20;
  }
};

class gChild: public Child {
public:
  gChild() { cout << "gChild constructor" << endl; }
  ~gChild() { cout << "gChild destructor" << endl; }

  int var() {
    cout << "gChild::var()";
    return 30;
  }
  virtual int foo() {
    cout << "gChild::foo()";
    return 30;
  }
  int bar() {
    cout << "gChild::bar()";
    return 30;
  }
};

int main(int argc, char **argv) {
  Base *b = NULL;
  Child *c = NULL;
  
  //b = new Base(); error
  
  b = new Child();
  cout << " var() = " << b->var() << endl;  
  cout << " foo() = " << b->foo() << endl;
  cout << " bar() = " << b->bar() << endl;
  delete b;
  
  b = new gChild();
  cout << " var() = " << b->var() << endl;    
  cout << " foo() = " << b->foo() << endl;
  cout << " bar() = " << b->bar() << endl;
  delete b;
  
  c = new gChild();
  cout << " var() = " << c->var() << endl;    
  cout << " foo() = " << c->foo() << endl;
  cout << " bar() = " << c->bar() << endl;
  delete b;

}
