// --
// new point for class hirarchy

#include<assert.h>

#include "point_new.h"

const void *PointNew;
const void *PointClass;

static void *PointNew_constructor(void *_self, va_list *app)
{
  struct PointNew *self = super_constructor(PointNew, _self, app);
  self->x = va_arg(*app, int);
  self->y = va_arg(*app, int);
  return self;
}

static void *PointClass_constructor(void *_self, va_list *app)
{
  struct PointClass *self = super_constructor(PointClass, _self, app);

  typedef void (*voidf)();
  voidf selector;
  va_list ap;
  va_copy(ap, *app);
  while((selector = va_arg(ap, voidf)))
  {
    voidf method = va_arg(ap, voidf);
    if(selector == (voidf)pn_draw){ *(voidf *) &self->pn_draw = method; }
  } 

  return self;
}

static void PointNew_draw(const void *_self)
{
  const struct PointNew *self = _self;
  //super_pn_draw(PointNew, _self);
  printf("PointNew method draw at %d, %d\n", self->x, self->y);
}

void super_pn_draw(const void *class, const void *self)
{
  ;
  //super(class_of(self))->pn_draw(self);
}

void pn_draw(const void *_self)
{
  const struct PointClass *const *cp = _self;
  assert(_self && *cp && (*cp)->pn_draw);
  (*cp)->pn_draw(_self);
}

void pn_move(void *_self, int dx, int dy)
{
  struct PointNew *self = _self;
  self->x += dx, self->y += dy;
}

void init_point_new(void)
{
  if(!PointClass){ PointClass = new_cls_obj(Cls, "Point Class", Cls, sizeof(struct PointClass), constructor, PointClass_constructor, 0); }
  if(!PointNew){ PointNew = new_cls_obj(PointClass, "Point", ClsObject, sizeof(struct PointNew), constructor, PointNew_constructor, pn_draw, PointNew_draw, 0); }
}