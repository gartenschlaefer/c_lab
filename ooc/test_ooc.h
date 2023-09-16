// --
// test ooc

#ifndef TEST_OOC_H
#define TEST_OOC_H

// --
// structs

struct Node
{
  struct Node *next;
  void *data;
};

struct TestClass
{
  const void *cls;
  int number;
};

// --
// externs

extern const void *Node;
extern const void *TestClass;

#endif