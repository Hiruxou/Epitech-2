/*
** array.c for ex05 in /home/heitzl_s/rendu/cpp_SKL/ex_05
** 
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
** 
** Started on  Sun Jan 11 00:04:41 2015 Serge Heitzler
** Last update Sun Jan 11 00:13:24 2015 Serge Heitzler
*/

#include <stdlib.h>
#include <stdarg.h>
#include "new.h"
#include "raise.h"
#include "array.h"

typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass* _array;
    size_t _idx;
} ArrayIteratorClass;

void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
  if (self == NULL)
    raise("Null Object");
  self->_array = va_arg(*args, ArrayClass *);
  self->_idx = va_arg(*args, size_t);
}

bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if(self->_idx == other->_idx && self->_array == other->_array)
    return (1);
  return (0);
}

bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (self->_array == other->_array && self->_idx > other->_idx)
    return (1);
  return (0);
}

bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  if (self == NULL || other == NULL)
    raise("Null Object");
  if (self->_array == other->_array && self->_idx < other->_idx)
    return (1);
  return (0);
}

void ArrayIterator_incr(ArrayIteratorClass* self)
{
  if (self == NULL)
    raise("Null Object");
  self->_idx++;
}

Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
  if (self == NULL)
    raise("Null Object");
  return (*((Container *)self->_array)->__getitem__)((Container *)self->_array, self->_idx);
}

void ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
  va_list ap;

  if (self == NULL)
    raise("Null Object");
  va_start(ap, self);
  delete(self->_array->_tab[self->_idx]);
  self->_array->_tab[self->_idx] = va_new(self->_array->_type, &ap);
  va_end(ap);
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ArrayIterator_eq,
            (binary_comparator_t) &ArrayIterator_gt,
            (binary_comparator_t) &ArrayIterator_lt,
        },
        (incr_t) &ArrayIterator_incr,
        (getval_t) &ArrayIterator_getval,
        (setval_t) &ArrayIterator_setval,
    },
    NULL,
    0
};

static Class* ArrayIterator = (Class*) &ArrayIteratorDescr;

void Array_ctor(ArrayClass* self, va_list* args)
{
  va_list ap;
  size_t i = 0;

  if (self == NULL)
    raise("Null Object");
  self->_size = va_arg(*args, size_t);
  self->_type = va_arg(*args, Class *);
  self->_tab = malloc(self->_size * sizeof(Object *));
  if (self->_tab == NULL)
    raise("Out of memory");
  while (i < self->_size)
    {
      va_copy(ap, *args);
      self->_tab[i] = va_new(self->_type, &ap);
      i++;
    }
}

void Array_dtor(ArrayClass* self)
{
  size_t i = 0;

  if (self == NULL)
    raise("Null Object");
  while (i < self->_size)
    {
      free(self->_tab[i]);
      i++;
    }
  free(self->_tab);
}

size_t Array_len(ArrayClass* self)
{
  if (self == NULL)
    raise("Null Object");
  return (self->_size);
}

Iterator* Array_begin(ArrayClass* self)
{
  if (self == NULL)
    raise("Null Object");
  return new(ArrayIterator, self, 0); 
}

Iterator* Array_end(ArrayClass* self)
{
  if (self == NULL)
    raise("Null Object");
  return new(ArrayIterator, self, self->_size - 1);
}

Object* Array_getitem(ArrayClass* self, ...)
{
  va_list ap;
  size_t index;
  
  if (self == NULL)
    raise("Null Object");
  va_start(ap, self);
  index = va_arg(ap, size_t);
  va_end(ap);
  if (index > self->_size)
    return NULL;
  return (self->_tab[index]);
}

void Array_setitem(ArrayClass* self, ...)
{
  va_list ap;
  size_t index;
  
  if (self == NULL)
    raise("Null Object");
  va_start(ap, self);
  index = va_arg(ap, size_t);
  if (index > self->_size)
    return;
  delete(self->_tab[index]);
  self->_tab[index] = va_new(self->_type, &ap);
  va_end(ap);
}

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
    },
    NULL, 0, NULL
};

Class* Array = (Class*) &_descr;
