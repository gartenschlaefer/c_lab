// --
// command pattern

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdarg.h>

#include "command.h"

struct Command *Command_New(void)
{
  // define constructor
  struct Command *command = malloc(sizeof(struct Command));
  assert(command);

  // constructor
  command->execute = Command_execute;
  command->child = NULL;

  return command;
}


void *Command_Nothing_New(void)
{
  // super
  struct Command *command = Command_New();

  // actual command
  struct CommandNothing *command_nothing = malloc(sizeof(struct CommandNothing));

  // constructor
  command_nothing->count = 0;
  command_nothing->command = command;
  command_nothing->get_count = Command_Nothing_get_count;

  // specify child
  command->child = command_nothing;

  // overwrite methods
  command->execute = Command_Nothing_execute;

  return command;
}

void Command_Delete(struct Command *command)
{
  if(command->child)
  { 
    struct CommandNothing *cn = command->child;
    free(cn);
    command->child = NULL;
  }
  free(command);
}

static void Command_execute(void *_self)
{
  struct Command *self = _self;
  printf("execute base command\n");
}

static void Command_Nothing_execute(void *_self)
{
  struct Command *self = _self;
  struct CommandNothing *cn = self->child;
  cn->count++;
  printf("nothing command but count: %i\n", cn->get_count(cn));
}

static int Command_Nothing_get_count(void *_self)
{
  struct CommandNothing *self = _self;
  return self->count;
}

void Command_test(void)
{
  // create instances
  struct Command *command = Command_New();
  struct Command *command_n = Command_Nothing_New();

  printf("command: %p\n", command);
  printf("command_nothing: %p\n", command_n);

  // do something
  command->execute(command);
  command->execute(command);
  command_n->execute(command_n);
  command_n->execute(command_n);

  // access new stuff
  struct CommandNothing *cn = command_n->child; 
  printf("get count: %i\n", cn->get_count(command_n->child));

  Command_Delete(command);
  Command_Delete(command_n);


  // access new stuff
  cn = command_n->child;
  //printf("get count: %i\n", cn->get_count(command_n->child));

  printf("command: %p\n", command);
  printf("command_nothing: %p\n", command_n);
}