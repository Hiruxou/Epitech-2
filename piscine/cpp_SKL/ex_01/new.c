/*
** new.c for ex01 in /home/heitzl_s/rendu/cpp_SKL/ex_01
** 
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
** 
** Started on  Sat Jan 10 23:50:23 2015 Serge Heitzler
** Last update Sat Jan 10 23:50:24 2015 Serge Heitzler
*/

#include "new.h"
#include "raise.h"
#include <string.h>

void *new(Class *class)
{
  Object *obj;
  
  obj = malloc(class->__size__);
  if (obj == NULL)
    raise("Out of memory");
  memcpy(obj, class, class->__size__);
  class->__init__(obj);
  return (obj);
}

void	delete(Object *ptr)
{
  Class *class;

  class = ptr;
  class->__del__(ptr);
  free(ptr);
}
