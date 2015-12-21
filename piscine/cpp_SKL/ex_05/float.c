/*
** char.c for ex04 in /home/heitzl_s/rendu/cpp_SKL/ex_04
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat Jan 10 10:33:46 2015 Serge Heitzler
** Last update Sun Jan 11 00:01:22 2015 Serge Heitzler
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "new.h"
#include "raise.h"
#include "float.h"

typedef struct FloatClass {
  Class base;
  float c;
} FloatClass;

static bool Float_eq(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((FloatClass*)self)->c == ((FloatClass*)other)->c)
    return 1;
  return 0;
}

static bool Float_lt(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((FloatClass*)self)->c < ((FloatClass*)other)->c)
    return 1;
  return 0;
}

static bool Float_gt(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((FloatClass*)self)->c > ((FloatClass*)other)->c)
    return 1;
  return 0;
}

static FloatClass *Float_div(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((FloatClass*)other)->c == 0)
    raise("Floating Point Exception");
  return new(Float, ((FloatClass*)self)->c / ((FloatClass*)other)->c);
}

static FloatClass *Float_mul(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Float, ((FloatClass*)self)->c * ((FloatClass*)other)->c);
}

static FloatClass *Float_add(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Float, ((FloatClass*)self)->c + ((FloatClass*)other)->c);
}

static FloatClass *Float_sub(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Float, ((FloatClass*)self)->c - ((FloatClass*)other)->c);
}

static char const *Float_to_string(Object *self)
{
  char *str;

  if (self == NULL)
    raise("Null Object");
  str = malloc(30 * sizeof(char));
  if (str == NULL)
    raise("Out of memory");
  memset(str, 0, 30);
  snprintf(str, 30, "%f", ((FloatClass*)self)->c);

  return str;
}

static void Float_ctor(Object *self, va_list *args)
{
  if (self)
    ((FloatClass*)self)->c = va_arg(*args, double);
}

static void Float_dtor(Object *self)
{
  if (self)
    ((FloatClass*)self)->c = 0;
}

static FloatClass _description = {
  {
    sizeof(FloatClass),
    "Float",
    &Float_ctor,
    &Float_dtor,
    (to_string_t)&Float_to_string,
    (binary_operator_t)&Float_add,
    (binary_operator_t)&Float_sub,
    (binary_operator_t)&Float_mul,
    (binary_operator_t)&Float_div,
    (binary_comparator_t)&Float_eq,
    (binary_comparator_t)&Float_gt,
    (binary_comparator_t)&Float_lt
  },
  0
};

Class *Float = (Class*) &_description;
