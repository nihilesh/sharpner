#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x, c = 0;

  //'fool' gcc not to optimize code too much
  while( c < 1000000 ) {
    x =  rand();
    if (__builtin_expect((x==38),1)) {
      x += 10;
    }  else {
      x=0;
      printf("false branch\n");
    }
    //execute  some more code afterwards
    c++;
    
  }
  return x;
}
