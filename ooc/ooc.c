// --
// ooc functionalities

#include<stdio.h>
#include<assert.h>

#include "ooc.h"

int heap[MANY];

/* ------------------------------------------------------------------*
 *            new class instance
 * ------------------------------------------------------------------*/

void *new_simple(const void *type, ...)
{
  printf("\nheap adr (in new): %p\n", heap);
  int *p;
  for(p = heap + 1; p < heap + MANY; ++p)
  {
    printf("check heap: %p\n", p);
    if(!*p){ break; }
  }

  printf("new in heap: %p\n", p);
  assert(p < heap + MANY);

  // init with memory
  *p = MANY;

  return p;
}

void *new_cls(const void *cls, ...)
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