// --
// set

#include<assert.h>
#include<stdio.h>

#include "set.h"
#include "object.h"
#include "ooc.h"

const void *Set;
const void *Set_struct = &_Set;

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

void *add_struct(void *_set, const void *_element)
{
  struct Set *set = _set;
  struct Object *element = (void *)_element;

  assert(set);
  assert(element);
  if(!element->in){ element->in = set; }
  else{ assert(element->in == set); }

  ++element->count, ++set->count;
  return element;
}

void *contains(const void *_set, const void *_element)
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

void *contains_struct(const void *_set, const void *_element)
{
  const struct Object *element = _element;

  assert(_set);
  assert(element);

  return ((element->in == _set) ? (void *)element : 0);
}

unsigned count(const void *_set)
{
  const struct Set *set = _set;
  assert(set);
  return set->count;
}