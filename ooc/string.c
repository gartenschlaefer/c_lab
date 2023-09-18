// --
// string

#include<string.h>
#include<assert.h>
#include<stdio.h>

#include "ooc.h"
#include "string.h"


// bind
static const struct Class _String = { .size = sizeof(struct String), .constructor = String_constructor, .destructor = String_destructor };
const void *String = &_String;

static void *String_constructor(void *_self, va_list *app)
{
  struct String *self = _self;
  const char *text = va_arg(*app, const char *);
  self->text = malloc(strlen(text) + 1);
  assert(self->text);
  strcpy(self->text, text);
  //self->print = String_print;
  return self;
}

static void *String_destructor(void *_self)
{
  struct String *self = _self;
  free(self->text);
  self->text = 0;
  return self;
}

char *String_print(void *_self)
{
  struct String *self = _self;
  printf("%s", self->text);
}