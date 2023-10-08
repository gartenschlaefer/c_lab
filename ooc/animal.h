#ifndef ANIMAL_H
#define ANIMAL_H

struct Animal
{
  char *speech;
  void *(*speak)(struct Animal *self);
};

struct Animal *Animal_constructor(struct Animal *animal, char *speech);
void *Animal_speak(struct Animal *animal);

#endif