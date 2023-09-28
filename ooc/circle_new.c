// --
// circle

#include<stdio.h>

#include "cls_object.h"
#include "circle_new.h"

const void *CircleNew;

static void *CircleNew_constructor(void *_self, va_list *app)
{
  struct CircleNew *self = super_constructor(CircleNew, _self, app);
  self->rad = va_arg(*app, int);
  return self;
}

static void CircleNew_draw(const void *_self)
{
  const struct CircleNew *self = _self;
  printf("circle at %d, %d with rad %d\n", self->_.x, self->_.y, self->rad);
}


void init_circle_new(void)
{
  if(!CircleNew)
  {
    init_point_new();
    CircleNew = new_cls_obj(PointClass, "Circle", PointNew, sizeof(struct CircleNew), constructor, CircleNew_constructor, pn_draw, CircleNew_draw, 0);
  }
}
