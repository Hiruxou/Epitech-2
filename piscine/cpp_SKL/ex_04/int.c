/*
** char.c for ex04 in /home/heitzl_s/rendu/cpp_SKL/ex_04
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat Jan 10 10:33:46 2015 Serge Heitzler
** Last update Sun Jan 11 00:01:38 2015 Serge Heitzler
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "new.h"
#include "raise.h"
#include "int.h"

typedef struct IntClass {
  Class base;
  int c;
} IntClass;

static bool Int_eq(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((IntClass*)self)->c == ((IntClass*)other)->c)
    return 1;
  return 0;
}

static bool Int_lt(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((IntClass*)self)->c < ((IntClass*)other)->c)
    return 1;
  return 0;
}

static bool Int_gt(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((IntClass*)self)->c > ((IntClass*)other)->c)
    return 1;
  return 0;
}

static IntClass *Int_div(const Object *self, const Object *other)
{
  if (other == NULL || self == NULL)
    raise("Null Object");
  if (((IntClass*)other)->c == 0)
    raise("Floating Point Exception");
  return new(Int, ((IntClass*)self)->c / ((IntClass*)other)->c);
}

static IntClass *Int_mul(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Int, ((IntClass*)self)->c * ((IntClass*)other)->c);
}

static IntClass *Int_add(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Int, ((IntClass*)self)->c + ((IntClass*)other)->c);
}

static IntClass *Int_sub(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Int, ((IntClass*)self)->c - ((IntClass*)other)->c);
}

static char const *Int_to_string(Object *self)
{
  char *str;

  if (self == NULL)
    raise("Null Object");
  str = malloc(15 * sizeof(char));
  if (str == NULL)
    raise("Out of memory");
  memset(str, 0, 15);
  snprintf(str, 15, "%i", ((IntClass*)self)->c);
  return str;
}

static void Int_ctor(Object *self, va_list *args)
{
  if (self)
    ((IntClass*)self)->c = va_arg(*args, int);
}

static void Int_dtor(Object *self)
{
  if (self)
    ((IntClass*)self)->c = 0;
  memset(self, 0, sizeof(IntClass));
}

static IntClass _description = {
  {
    sizeof(IntClass),
    "Int",
    &Int_ctor,
    &Int_dtor,
    (to_string_t)&Int_to_string,
    (binary_operator_t)&Int_add,
    (binary_operator_t)&Int_sub,
    (binary_operator_t)&Int_mul,
    (binary_operator_t)&Int_div,
    (binary_comparator_t)&Int_eq,
    (binary_comparator_t)&Int_gt,
    (binary_comparator_t)&Int_lt
  },
  0
};

Class *Int = (Class*) &_description;
