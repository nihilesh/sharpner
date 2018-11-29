#include <iostream>
using namespace std;

class base {
protected:
public:
  base() { cout << "Base constructor called" << endl; }
  ~base() { cout << "Base destructor called" << endl; }  
};

class derived: public base {
public:
  derived() { cout << "Derived constructor called" << endl; }
  ~derived() { cout << "Derived destructor called" << endl; }  
};

class vbase {
protected:
public:
  vbase() { cout << "vBase constructor called" << endl; }
  virtual ~vbase() { cout << "vBase destructor called" << endl; }  
};

class vderived: public vbase {
public:
  vderived() { cout << "vDerived constructor called" << endl; }
  ~vderived() { cout << "vDerived destructor called" << endl; }  
};


int main( int argc, char **argv ) {
  base *b = NULL;
  b = new derived();
  delete b;  
  vbase *vb = NULL;
  vb = new vderived();
  delete vb;
}
