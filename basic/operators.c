// --
// hello world program

#include <stdio.h>

#define f_round(x) ((unsigned) (x + .5))
#define f_round_int(d) ( (int) (d + (d > 0 ? 0.5 : -0.5)) )

// main
int main(void)
{
  unsigned char a = 0;
  unsigned char b = 1;
  unsigned char c = 2;
  unsigned char d = 3;

  printf("%i mod 2 = %i\n", a, a % 2);
  printf("%i mod 2 = %i\n", b, b % 2);
  printf("%i mod 2 = %i\n", c, c % 2);
  printf("%i mod 2 = %i\n", d, d % 2);

  unsigned char tele[16] = { 0, 6, 8, 0, 2, 1, 0, 11, 11, 11, 11};
  for(unsigned char i = 0; ((tele[i] != 11) && (i < 16)); i++)
  {
    printf("tele at pos %i is: %i\n", i, tele[i]);
  }

  // <
  if(a < 2){ printf("%i < 2\n", a); }
  if(b < 2){ printf("%i < 2\n", b); }
  if(c < 2){ printf("%i < 2\n", c); }

  // round
  float e[6] = { 0.1, 0.49, 0.5, 0.51, 0.9, 1.1 };
  float e_r[6] = { 0.1, 0.49, 0.5, 0.51, 0.9, 1.1 };

  for(unsigned char i = 0; i < 6; i++){ e_r[i] = f_round_int(e[i]); }

  for(unsigned char i = 0; i < 6; i++){ printf("%f r: %f\n", e[i], e_r[i]); }
  for(unsigned char i = 0; i < 6; i++){ printf("%f r: %f\n", e[i], f_round(e[i])); }
  for(unsigned char i = 0; i < 6; i++){ printf("%f r: %f\n", e[i], f_round_int(e[i])); }
  for(unsigned char i = 0; i < 6; i++){ printf("%f r: %d\n", e[i], (int)(e[i] + .5)); }

  printf("%f\n", e[0] - c);

  printf("%i if %i\n", a, (a ? 1 : 0));
  printf("%i if %i\n", b, (b ? 1 : 0));
  printf("%i if %i\n", c, (c ? 1 : 0));


  float f = 200.0 / 3.0;
  int g = f_round_int(f);

  printf("\nf: %f, round: %i or %i\n", f, g, f_round_int(200.0 / 3.0));

  printf("\ncompare1: %d\n", (unsigned char)(10 == 0));
  printf("compare2: %d\n", (unsigned char)(10 == 10));

  printf("\nnot 10: %d\n", (unsigned char)(!10));
  printf("\nnot 0: %d\n", (unsigned char)(!0));


  return 0;
}