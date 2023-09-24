// --
// class object

const void *ClsObject;

#include<assert.h>
#include<stdio.h>
#include<stddef.h>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>

#include "cls_object.h"

// static const struct Cls _Cls_Object;
// const void *ClsObject = &_Cls_Object;
// static const struct Cls _Cls;
// const void *Cls = &_Cls;

// init
static const struct Cls object[] = 
{ 
  {
    ._ = { object + 1 }, .name = "Object", .super = object, .size = sizeof(struct ClsObject),
    ClsObject_constructor, ClsObject_destructor, 0, ClsObject_puto
  },
  {
    ._ = { object + 1 }, .name = "Class", .super = object, .size = sizeof(struct Cls),
    Cls_constructor, Cls_destructor, 0, ClsObject_puto
  }
};

const void *ClsObject = object;
const void *Cls = object + 1;


static void *ClsObject_constructor(void *_self, va_list *app)
{
  ;
}

static void *ClsObject_destructor(void *_self)
{
  ;
}

static void *Cls_constructor(void *_self, va_list *app)
{
  struct Cls *self = _self;
  self->name = va_arg(*app, char *);
  self->super = va_arg(*app, struct Cls *);
  self->size = va_arg(*app, size_t);
  assert(self->super);

  // copy super class
  const size_t offset = offsetof(struct Cls, constructor);
  memcpy((char *) self + offset, (char *) self->super + offset, size_of_cls(self->super) - offset);

  // method pairs
  {
    typedef void (*voidf)();
    voidf selector;
    va_list ap;
    va_copy(ap, *app);
    while((selector = va_arg(ap, voidf)))
    {
      voidf method = va_arg(ap, voidf);
      if(selector == (voidf)constructor){ *(voidf *) &self->constructor = method; }
      else if(selector == (voidf)destructor){ *(voidf *) &self->destructor = method; }
      else if(selector == (voidf)differ){ *(voidf *) &self->differ = method; }
      else if(selector == (voidf)puto){ *(voidf *) &self->puto = method; }
    } 
  }
  return self;
}

static void *Cls_destructor(void *_self)
{
  struct Cls *self = _self;
  printf("%s: cannot destroy class\n", self->name);
  return 0;
}

const void *super(const void *_self)
{
  const struct Cls *self = _self;
  assert(self && self->super);
  return self->super;
}

void *new_cls_obj(const void *_class, ...)
{
  const struct Cls *class = _class;
  struct ClsObject *object;
  va_list ap;
  printf("new class: %p with size %i\n", class, class->size);
  assert(class && class->size);
  object = calloc(1, class->size);
  assert(object);
  object->cls = class;
  va_start(ap, _class);
  object = constructor(object, &ap);
  va_end(ap);
  return object;
}

void delete_cls_obj(void *self)
{
  const struct Cls **cp = self;
  if(self && *cp && (*cp)->destructor){ self = (*cp)->destructor(self); }
  free(self);
}

static int ClsObject_puto(const void *_self, FILE *fp)
{
  const struct Cls *class = class_of(_self);
  return fprintf(fp, "%s at %p\n", class->name, _self);
}


const void *class_of(const void *_self)
{
  const struct ClsObject *self = _self;
  assert(self && self->cls);
  return self->cls;
}

const int size_of_cls(const void *_self)
{
  const struct Cls *cls = class_of(_self);
  return cls->size;
}

void *constructor(void *_self, va_list *app)
{
  const struct Cls *class = class_of(_self);
  assert(class->constructor);
  return class->constructor(_self, app);
}

void *destructor(void *_self)
{
  const struct Cls *class = class_of(_self);
  assert(class->destructor);
  return class->destructor(_self);
}

int differ(const void *self, const void *b)
{
  printf("differ_cls_obj\n");
  return 1;
}

int puto(const void *_self, FILE *fp)
{
  const struct Cls *cls = class_of(_self);
  fprintf(fp, "class: %s puto_cls_obj\n", cls->name);
  return 0;
}

void *super_constructor(const void *_class, void *_self, va_list *app)
{
  const struct Cls *superclass = super(_class);
  assert(_self && superclass->constructor);
  return superclass->constructor(_self, app);
}

void *super_destructor(const void *_class, void *_self)
{
  const struct Cls *superclass = super(_class);
  assert(_self && superclass->destructor);
  return superclass->destructor(_self);  
}