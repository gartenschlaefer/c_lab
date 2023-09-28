// --
// test object oriented c

#include<stdio.h>

#include "test_ooc.h"

#include "object.h"
#include "set.h"
#include "ooc.h"
#include "string.h"
#include "point.h"
#include "circle.h"
#include "cls_object.h"
#include "any.h"
#include "point_new.h"
#include "circle_new.h"

void test_simple_new(void)
{
  /**
   * simple heap with local memory
   */

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


void test_struct_new(void)
{
  /**
   * uses dynamic memory 
   */

  void *s = new_struct(Set_struct);

  printf("new set: %p\n", s);
  void *o = new_struct(Object_struct);
  printf("new object: %p\n", o);

  void *a = add_struct(s, o);
  void *b = add_struct(s, new_struct(Object_struct));
  void *c = new_struct(Object_struct);

  // contains
  puts("\ncontains:");
  if(contains_struct(s, a) && contains_struct(s, b)){ puts("contains a and b: ok"); }
  if(!contains_struct(s, c)){ puts("does not contain c!"); }

  printf("elements in set: %i\n", count(s));
}


void test_string_cls(void)
{
  /**
   * test string class
   */

  struct String *s1 = new_cls(String, "hi");
  //void *s2 = new_cls(String, "there");

  printf("text: %s\n", s1->text);
} 


void test_draw_cls(int argc, char **argv)
{
  void *p;
  while(*++argv)
  {
    switch(**argv)
    {
      case 'p': p = new_cls(Point, 1, 2); break;
      case 'c': p = new_cls(Circle, 5, 6, 7); break;
      default: continue;
    }

    draw(p);
    move(p, 10, 10);
    draw(p);
    delete_cls(p);
  }
}


int main(int argc, char **argv)
{
  printf("--\nWelcome to Object-oriented C\n");

  // test simple
  //test_simple_new();
  //test_struct_new();
  //test_string_cls();

  //test_draw_cls(argc, argv);

  // any class
  // void *o = new_cls_obj(ClsObject);
  // const void *Any = new_cls_obj(Cls, "Any", ClsObject, sizeof(o), differ, Any_differ, 0);

  // void *a = new_cls_obj(Any);

  // puto(Any, stdout);
  // puto(o, stdout);
  // puto(a, stdout);

  // init points
  init_point_new();
  init_circle_new();

  void *p;
  while(*++argv)
  {
    switch(**argv)
    {
      case 'p': p = new_cls_obj(PointNew, 1, 2); break;
      case 'c': p = new_cls_obj(CircleNew, 5, 6, 7); break;
      default: continue;
    }

    printf("now draw %p\n", p);
    pn_draw(p);
    pn_move(p, 10, 10);
    pn_draw(p);
    delete_cls_obj(p);
  }

  return 0;
}