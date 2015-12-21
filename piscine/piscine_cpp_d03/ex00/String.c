/*
** String.c for  in /home/nicolaschr/rendu/piscine_cpp_d03/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:58:38 2015 Nicolas Charvoz
** Last update Fri Jan  9 10:35:59 2015 Nicolas Charvoz
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "String.h"

void StringInit(String *this, char const *s)
{
  if (s)
    this->str = strdup(s);
  else
    this->str = NULL;
}

void StringDestroy(String *this)
{
  if (this->str)
    free(this->str);
  memset(this, 0, sizeof(String));
}
