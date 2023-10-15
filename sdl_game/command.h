// --
// command pattern

#ifndef COMMAND_H
#define COMMAND_H

struct Class
{
  char *name;
  size_t size;
  void * (*constructor)(void *self, va_list *app);
  void * (*destructor)(void *self);
};

struct Command
{
  struct Class cls;
  void (*execute)(void *self);
  void *child;
};

struct CommandNothing
{
  struct Command *command;
  int count;
  int (*get_count)(void *self);
};

// header
struct Command *Command_New(void);
static void *Command_constructor(void *_self, va_list *app);

void *Command_Nothing_New(void);
void Command_Delete(struct Command *command);

static void Command_execute(void *_self);
static void Command_Nothing_execute(void *_self);
static int Command_Nothing_get_count(void *_self);
void Command_test(void);

#endif