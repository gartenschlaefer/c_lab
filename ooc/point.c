// --
// point

#include<stdio.h>

#include "ooc.h"

struct Point
{
  const void *class;
  int x, y;
};

static void *Point_constructor(void *_self, va_list *app)
{
  struct Point *self = _self;
  self->x = va_arg(*app, int);
  self->y = va_arg(*app, int);
  return self;
}

static void Point_draw(const void *_self)
{
  const struct Point *self = _self;
  printf("\".\" at %d, %d\n", self->x, self->y);
}

static const struct Class _Point = { .size = sizeof(struct Point), .constructor = Point_constructor, .destructor = NULL, .draw = Point_draw };
const void *Point = &_Point;

void move(void *_self, int dx, int dy)
{
  struct Point *self = _self;
  self->x += dx, self->y += dy;
}