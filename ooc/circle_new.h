// --
// Circle new

#ifndef CIRCLE_NEW_H
#define CIRCLE_NEW_H

#include "point_new.h"

extern const void *CircleNew;

struct CircleNew
{
  const struct PointNew _;
  int rad;
};


// function header
void init_circle_new(void);


#endif