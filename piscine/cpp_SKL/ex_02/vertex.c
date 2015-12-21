/*
** vertex.c for vertex in /home/garcia_t/rendu/cpp_SKL/ex_02
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Jan 10 10:24:15 2015 antoine garcia
** Last update Sat Jan 10 23:52:41 2015 Serge Heitzler
*/

#include <stdio.h>
#include "vertex.h"
#include "raise.h"
#include <string.h>
#include <stdlib.h>

typedef struct
{
  Class base;
  int x, y, z;
}VertexClass;

static void Vertex_ctor(Object *self, va_list *args)
{
  ((VertexClass*)self)->x = va_arg(*args, int);
  ((VertexClass*)self)->y = va_arg(*args, int);
  ((VertexClass*)self)->z = va_arg(*args, int);
}

static char *Vertex_to_string(Object *self)
{
  char *str;

  str = malloc(200 * sizeof(char));
  if (str == NULL)
    raise ("Out of memory");
  memset(str, 0, 200);
  snprintf(str, 200, "<%s (%i, %i, %i)>", ((VertexClass*)self)->base.__name__, ((VertexClass*)self)->x,((VertexClass*)self)->y, ((VertexClass*)self)->z);
  return (str);
}

static void Vertex_dtor(Object *self)
{
  if (self)
    {
      ((VertexClass*)self)->x = 0;
      ((VertexClass*)self)->y = 0;
      ((VertexClass*)self)->z = 0;
    }
  memset(self, 0, sizeof(VertexClass));
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, (to_string_t)&Vertex_to_string },
  0, 0, 0
};

Class* Vertex = (Class*) &_description;
