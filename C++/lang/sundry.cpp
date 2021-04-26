#include <iostream>
using namespace std;

class Add {
  int i;
  int j;
public:
  Add(int i_, int j_): i{i_}, j{j_}{}
  virtual ~Add(){}
  int operator() (int k) {
    i += k;
    return i;
  }
};

int main() {
  Add a(2, 3);
  cout << a(3) << endl;
  return 0;
}
