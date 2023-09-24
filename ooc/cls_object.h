// --
// class object

#ifndef CLS_OBJECT_H
#define CLS_OBJECT_H

#include<stdlib.h>
#include<stdarg.h>
#include<stdio.h>

extern const void *ClsObject;
extern const void *Cls;

// class object
struct ClsObject
{
  const struct Cls *cls;
};

// class struct
struct Cls
{
  const struct ClsObject _;
  const char *name;
  const struct Cls *super;
  size_t size;
  void * (*constructor)(void *self, va_list *app);
  void * (*destructor)(void *self);
  int (*differ)(const void *self, const void *b);
  int (*puto)(const void *self, FILE *fp);
};


// header
static void *ClsObject_constructor(void *_self, va_list *app);
static void *ClsObject_destructor(void *_self);
static void *Cls_constructor(void *_self, va_list *app);
static void *Cls_destructor(void *_self);

const void *super(const void *_self);
void *new_cls_obj(const void *class, ...);
void delete_cls_obj(void *self);

static int ClsObject_puto(const void *_self, FILE *fp);

const void *class_of(const void *_self);
const int size_of_cls(const void *_self);

void *constructor(void *_self, va_list *app);
void *destructor(void *_self);
int differ(const void *_self, const void *b);
int puto(const void *_self, FILE *fp);

void *super_constructor(const void *_class, void *_self, va_list *app);
void *super_destructor(const void *_class, void *_self);


#endif