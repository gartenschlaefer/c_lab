#ifndef COW_H
#define COW_H

#include "animal.h"

struct Cow
{
  struct Animal base;
  void *(*speak)(struct Animal *animal);
};

struct Cow *Cow_new(void);

#endif