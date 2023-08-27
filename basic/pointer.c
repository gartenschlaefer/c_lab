// --
// pointer

#include <stdio.h>

struct B
{
  int b;
};

struct A
{
  int a;
  struct B *b;
};


struct C
{
  int c;
  struct C *cp;
};


struct D
{
  int d;
};


void foo(int *p)
{
  printf("n foo: %i\n", *p);
  *p += 1;
  printf("n foo2: %i\n", *p);
}

void bar(int *p)
{
  int a = *p;

  printf("n bar: %i\n", *p);
  a++;
  *p = a;
  printf("n bar2: %i\n", *p);
  printf("a: %i\n", a);
}


int main(void)
{
  int n = 10;
  int *p_n = &n;

  // structs
  struct B b = { .b = 200 };
  struct A a = { .a = 100, .b = &b };

  struct A *p_a = &a;

  foo(&n);
  foo(p_n);
  foo(p_n);

  bar(&b.b);

  bar(&a.b->b);
  bar(&p_a->b->b);

  printf("n: %i\n", n);
  printf("b: %i\n", (*p_a->b).b);

  p_a->b->b = 300;
  printf("b: %i\n", p_a->b->b);

  struct C c2 = { .c = 2, .cp = NULL };
  struct C c1 = { .c = 1, .cp = &c2 };

  printf("c1: %i\n", c1.c);
  printf("c2: %i\n", c2.c);
  c1 = *c1.cp;

  printf("c1: %i\n", c1.c);
  printf("c2: %i\n", c2.c);

  c2.c = 3;
  //c1.c = 3;
  printf("c1: %i\n", c1.c);
  printf("c2: %i\n", c2.c);

  struct D d1 = { .d = 1 };
  struct D d2 = { .d = 2 };

  printf("d1: %i\n", d1.d);
  printf("d2: %i\n", d2.d);

  d1 = d2;
  printf("d1: %i\n", d1.d);
  printf("d2: %i\n", d2.d);
  foo(&d1.d);
  printf("d1: %i\n", d1.d);
  printf("d2: %i\n", d2.d);

  // arrays
  int e1[3] = { 1, 2, 3 };
  unsigned char e2[3] = { 1, 2, 3 };
  void *p_e = e1;

  for(int i = 0; i < 3; i++){ printf("val: %d, pointer: %p\n", p_e, p_e); p_e++; } 

  return 0;
}