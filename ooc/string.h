// --
// string

#ifndef STRING_H
#define STRING_H


// externs
extern const void *String;

// class structs
struct String
{
  const void *cls;
  char *text;
  //char *(*print)(void);
  //char *(*get_text)(void);
};

// header
static void *String_constructor(void *_self, va_list *app);
static void *String_destructor(void *_self);

char * String_print(void *_self);

#endif