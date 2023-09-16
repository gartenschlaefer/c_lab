// --
// ooc functionalities

#ifndef OOC_H
#define OOC_H

#include<stdarg.h>

// class struct
struct Class
{
  size_t size;
  void * (*constructor)(void *self, va_list *app);
  void * (*destructor)(void *self);
};

// header
void *new(const void *cls, ...);
void delete(void *object);

#endif