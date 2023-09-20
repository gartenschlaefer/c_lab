// --
// circle

#include<stdio.h>

#include "ooc.h"
#include "circle.h"

struct Circle
{
  const struct Point _;
  int rad;
};

static void *Circle_constructor(void *_self, va_list *app)
{
  struct Circle *self = ((const struct Class *) Point)->constructor(_self, app);
  self->rad = va_arg(*app, int);
  return self;
}

static void Circle_draw(const void *_self)
{
  const struct Circle *self = _self;
  printf("circle at %d, %d with rad %d\n", self->_.x, self->_.y, self->rad);
}

static const struct Class _Circle = { .size = sizeof(struct Circle), .constructor = Circle_constructor, .destructor = NULL, .draw = Circle_draw };
const void *Circle = &_Circle;
