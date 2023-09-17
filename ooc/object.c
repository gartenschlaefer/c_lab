// --
// object

#include "object.h"

const void *Object;
const void *Object_struct = &_Object;

int differ(const void *a, const void *b)
{
  return a != b;
}