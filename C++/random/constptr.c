#include <stdlib.h>
#include <stdio.h>

int main( int argc, char** argv ) {
  int a = 5, b = 5;
  const int c = 10;

  // c = 15; error 
  const int *cp = &a; //Ok
  //*cp = 10; error
  cp = &c; //Ok
  
  int const *pc = &a; //Ok
  //*pc = 10; error
  pc = &b; //Ok ??-- expected error here.

  int *p = &a;
  p = &c;  //Warning - discards 'const' qualifier

  //Something to avoid warning
  if ( (pc == cp) && p ) {
    a = 6;
  }

  return 0;
}
