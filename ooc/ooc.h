// --
// ooc functionalities

#ifndef OOC_H
#define OOC_H

#include<stdlib.h>
#include<stdarg.h>

// defines
#if !defined MANY || MANY < 1
#define MANY 10
#endif

// heap
extern int heap[MANY];


// class struct
struct Class
{
  size_t size;
  void * (*constructor)(void *self, va_list *app);
  void * (*destructor)(void *self);
};

// header
void *new_simple(const void *type, ...);
void *new_struct(const void *type, ...);
void *new_cls(const void *cls, ...);
void delete_cls(void *object);

void *clone(const void *self);
int differ(const void *self, const void *b);
size_t my_sizeof(const void *self);

#endif