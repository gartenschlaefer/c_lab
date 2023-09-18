// --
// set

#ifndef SET_H
#define SET_H

// externs
extern const void *Set;
extern const void *Set_struct;

// structs
struct Set
{
  const void *cls;
  unsigned count;
};

static const size_t _Set = sizeof(struct Set);

// header
void *add(void *_set, const void *_element);
void *add_struct(void *_set, const void *_element);
void *contains(const void *_set, const void *_element);
void *contains_struct(const void *_set, const void *_element);
unsigned count(const void *_set);


#endif