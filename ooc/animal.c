#include "animal.h"
#include<stdio.h>

struct Animal *Animal_constructor(struct Animal *animal, char *speech)
{
  animal->speech = speech;
  animal->speak = Animal_speak;

  return animal;
}

void *Animal_speak(struct Animal *animal)
{
  printf("\nAnimal speech: %s\n", animal->speech);
}