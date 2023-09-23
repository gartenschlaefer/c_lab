// --
// object

#ifndef OBJECT_H
#define OBJECT_H

#include "stdlib.h"
#include "set.h"

// externs
extern const void *Object;
extern const void *Object_struct;

struct Object
{
  unsigned count;
  struct Set *in;
};

static const size_t _Object = sizeof(struct Object);

// header
//int differ(const void *a, const void *b);

#endif