// --
// new point for class hirarchy

#ifndef POINT_NEW
#define POINT_NEW

#include "cls_object.h"

extern const void *PointNew;
extern const void *PointClass;

struct PointNew
{
  const struct ClsObject _;
  int x, y;
};

struct PointClass
{
  const struct Cls _;
  void (*pn_draw)(const void *self);
};

void pn_draw(const void *self);
void pn_move(void *point, int x, int y);
void super_pn_draw(const void *class, const void *self);

void init_point_new(void);

#endif