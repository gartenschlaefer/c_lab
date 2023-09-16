// --
// ooc functionalities

#include<stdlib.h>
#include<assert.h>

#include "ooc.h"


/* ------------------------------------------------------------------*
 *            new class instance
 * ------------------------------------------------------------------*/

void *new(const void *cls, ...)
{
  const struct Class *class = cls;
  void *p = calloc(1, class->size);
  assert(p);
  *(const struct Class **) p = class;
  if(class->constructor)
  {
    va_list ap;
    va_start(ap, cls);
    p = class->constructor(p, &ap);
    va_end(ap);
  }
  return p;
}