
#include<stdlib.h>
#include "cow.h"

struct Cow *Cow_new(void)
{
  struct Cow *cow = calloc(1, sizeof(struct Cow));
  struct Animal *animal = Animal_constructor((struct Animal*)cow, "Moooohh");
  cow->speak = animal->speak;
  return cow;
}