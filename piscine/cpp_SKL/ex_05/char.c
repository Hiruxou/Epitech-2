/*
** char.c for ex04 in /home/heitzl_s/rendu/cpp_SKL/ex_04
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sat Jan 10 10:33:46 2015 Serge Heitzler
** Last update Sun Jan 11 00:01:06 2015 Serge Heitzler
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "new.h"
#include "raise.h"
#include "char.h"

typedef struct CharClass {
  Class base;
  char c;
} CharClass;

static bool Char_eq(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((CharClass*)self)->c == ((CharClass*)other)->c)
    return 1;
  return 0;
}

static bool Char_lt(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((CharClass*)self)->c < ((CharClass*)other)->c)
    return 1;
  return 0;
}

static bool Char_gt(Object *self, Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((CharClass*)self)->c > ((CharClass*)other)->c)
    return 1;
  return 0;
}

static CharClass *Char_div(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (((CharClass*)other)->c == 0)
    raise("Floating Point Exception");
  return new(Char, ((CharClass*)self)->c / ((CharClass*)other)->c);
}

static CharClass *Char_mul(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Char, ((CharClass*)self)->c * ((CharClass*)other)->c);
}

static CharClass *Char_add(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Char, ((CharClass*)self)->c + ((CharClass*)other)->c);
}

static CharClass *Char_sub(const Object *self, const Object *other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  return new(Char, ((CharClass*)self)->c - ((CharClass*)other)->c);
}

static char const *Char_to_string(Object *self)
{
  char *str;

  if (self == NULL)
    raise("Null Object");
  str = malloc(2 * sizeof(char));
  if (str == NULL)
    raise("Out of memory");
  str[0] = ((CharClass*)self)->c;
  str[1] = 0;
  return str;
}

static void Char_ctor(Object *self, va_list *args)
{
  if (self)
    ((CharClass*)self)->c = va_arg(*args, int);
}

static void Char_dtor(Object *self)
{
  if (self)
    ((CharClass*)self)->c = 0;
  memset(self, 0, sizeof(CharClass));
}

static CharClass _description = {
  {
    sizeof(CharClass),
    "Char",
    &Char_ctor,
    &Char_dtor,
    (to_string_t)&Char_to_string,
    (binary_operator_t)&Char_add,
    (binary_operator_t)&Char_sub,
    (binary_operator_t)&Char_mul,
    (binary_operator_t)&Char_div,
    (binary_comparator_t)&Char_eq,
    (binary_comparator_t)&Char_gt,
    (binary_comparator_t)&Char_lt
  },
  0
};

Class *Char = (Class*) &_description;
