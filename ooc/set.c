// --
// set

#include<assert.h>
#include<stdio.h>

#include "set.h"
#include "ooc.h"

const void *Set;

void *add(void *_set, const void *_element)
{
  const int *set = _set;
  const int *element = _element;

  printf("add: set: %p and heap: %p\n", set, heap);

  assert(set > heap && set < heap + MANY);
  assert(*set == MANY);
  assert(element > heap && element < heap + MANY);

  if(*element == MANY){ *(int *)element = set - heap; }
  else{ assert(* element == set - heap); }

  return (void *)element;
}

void *contains(void *_set, const void *_element)
{
  const int *set = _set;
  const int *element = _element;

  printf("contains: set: %p, element: %p\n", set, element);

  assert(set > heap && set < heap + MANY);
  assert(*set == MANY);
  assert(element > heap && element < heap + MANY);
  assert(*element);

  return ((*element == set - heap) ? (void *)element : 0);
}
