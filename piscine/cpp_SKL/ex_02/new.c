/*
** ex_02.c for ex_02 in /home/garcia_t/rendu/cpp_SKL/ex_02
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Jan 10 10:24:00 2015 antoine garcia
** Last update Sat Jan 10 22:23:25 2015 antoine garcia
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "new.h"
#include "raise.h"

Object	*va_new(Class *class, va_list *ap)
{
  Object	*obj;

  obj = malloc(class->__size__);
  if (obj == NULL)
    raise("Out of memory");
  memcpy(obj, class, class->__size__);
  class->__init__(obj, ap);
  va_end(*ap);
  return (obj);
}

Object *new(Class *class,...)
{
  va_list ap;

  va_start(ap, class);
  return (va_new(class, &ap));
}

void    delete(Object *ptr)
{
  Class *class;
  class = ptr;
  if (ptr != NULL)
    {
      if(class->__del__)
	class->__del__(ptr);
      free(ptr);
    }
}
