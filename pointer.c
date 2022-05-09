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
  return 0;
}