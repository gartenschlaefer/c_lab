// --
// type of

#include <stdio.h>

// main
int main(void)
{
  unsigned char a;
  int b;
  typeof(b) c = 2;

  printf("\ntype of c is same as b, value of c = %i\n", c);


  return 0;
}