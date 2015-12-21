/*
** point.c for point in /home/garcia_t/rendu/cpp_SKL/ex_02
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Jan 10 10:24:22 2015 antoine garcia
** Last update Sat Jan 10 23:53:10 2015 Serge Heitzler
*/

#include <stdio.h>
#include "point.h"
#include "raise.h"
#include <string.h>
#include <stdlib.h>

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(Object* self, va_list *args)
{
    ((PointClass*)self)->x = va_arg(*args, int);
    ((PointClass*)self)->y = va_arg(*args, int);
}

static void Point_dtor(Object* self)
{
  if (self)
    {
      ((PointClass*)self)->x = 0;
      ((PointClass*)self)->y = 0;
    }
  memset(self, 0, sizeof(PointClass));
}

static char *Point_to_string(Object *self)
{
  char *str;

  str = malloc(200 * sizeof(char));
  if (str == NULL)
    raise ("Out of memory");
  memset(str, 0, 200);
  snprintf(str, 200, "<%s (%i, %i)>", ((PointClass*)self)->base.__name__, ((PointClass*)self)->x,((PointClass*)self)->y);
  return (str);
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, (to_string_t)&Point_to_string},
    0, 0
};

Class* Point = (Class*) &_description;
