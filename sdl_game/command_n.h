// --
// command pattern

#ifndef COMMAND_N_H
#define COMMAND_N_H

struct Command_N
{
  void (*execute)(void *self);
};

struct Command_N_Nothing
{
  struct Command_N command;
  int count;
  int (*get_count)(void *self);
};

// header
struct Command_N *Command_N_New(void);
struct Command_N *Command_N_constructor(struct Command_N *command, void (*execute)(void *));

struct Command_N_Nothing *Command_N_Nothing_New(void);
void Command_N_Delete(struct Command_N *command);

static void Command_N_execute(void *_self);
static void Command_N_Nothing_execute(void *_self);
static int Command_N_Nothing_get_count(void *_self);

void Command_N_test(void);

#endif