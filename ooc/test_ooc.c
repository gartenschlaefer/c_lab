// --
// test object oriented c

#include<stdio.h>

#include "object.h"
#include "set.h"
#include "test_ooc.h"
#include "ooc.h"


void test_simple_new(void)
{
  void *s = new_simple(Set);

  printf("new set: %p\n", s);
  void *o = new_simple(Object);
  printf("new object: %p\n", o);

  void *a = add(s, o);
  void *b = add(s, new_simple(Object));
  void *c = new_simple(Object);

  // contains
  puts("\ncontains:");
  if(contains(s, a) && contains(s, b)){ puts("contains a and b: ok"); }
  if(!contains(s, c)){ puts("does not contain c!"); }
}


int main(void)
{
  printf("--\nWelcome to Object-oriented C\n");

  // test simple
  test_simple_new();


  //void *test_class = new(TestClass);
}