// --
// point

#ifndef POINT_H
#define POINT_H

extern const void *Point;

struct Point
{
  const void *class;
  int x, y;
};

void move(void *_self, int dx, int dy);


#endif