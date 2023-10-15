// --
// command pattern

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdarg.h>

#include "command_n.h"

struct Command_N *Command_N_New(void)
{
  // define constructor
  struct Command_N *command = malloc(sizeof(struct Command_N));
  assert(command);

  // constructor
  command = Command_N_constructor(command, Command_N_execute);

  return command;
}

struct Command_N *Command_N_constructor(struct Command_N *command, void (*execute)(void *))
{
  // constructor
  command->execute = execute;
}

struct Command_N_Nothing *Command_N_Nothing_New(void)
{
  // actual command
  struct Command_N_Nothing *command_nothing = malloc(sizeof(struct Command_N_Nothing));

  // super constructor
  struct Command_N *command = Command_N_constructor((struct Command_N *)command_nothing, Command_N_Nothing_execute);

  // constructor
  command_nothing->count = 0;
  command_nothing->get_count = Command_N_Nothing_get_count;

  return command_nothing;
}

// void Command_Delete(struct Command_N *command)
// {
//   if(command->child)
//   { 
//     struct Command_N_Nothing *cn = command->child;
//     free(cn);
//     command->child = NULL;
//   }
//   free(command);
// }

static void Command_N_execute(void *_self)
{
  struct Command_N *self = _self;
  printf("execute base command\n");
}

static void Command_N_Nothing_execute(void *_self)
{
  struct Command_N_Nothing *self = _self;
  self->count++;
  printf("nothing command but count: %i\n", self->get_count(self));
}

static int Command_N_Nothing_get_count(void *_self)
{
  struct Command_N_Nothing *self = _self;
  return self->count;
}

void Command_N_test(void)
{
  // create instances
  struct Command_N *command = Command_N_New();
  struct Command_N_Nothing *command_n = Command_N_Nothing_New();

  struct Command_N *c_command_n = (struct Command_N *)command_n;

  printf("command: %p\n", command);
  printf("command_nothing: %p\n", command_n);

  // do something
  command->execute(command);
  command->execute(command);
  c_command_n->execute(command_n);
  c_command_n->execute(command_n);

  // access new stuff
  printf("get count: %i\n", command_n->get_count(command_n));

  //Command_Delete(command);
  //Command_Delete(command_n);

  printf("command: %p\n", command);
  printf("command_nothing: %p\n", command_n);
}