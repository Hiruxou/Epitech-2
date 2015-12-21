/*
** String.c for  in /home/nicolaschr/rendu/piscine_cpp_d03/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:58:38 2015 Nicolas Charvoz
** Last update Fri Jan  9 11:31:28 2015 Nicolas Charvoz
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "String.h"

static void assign_c(String*, char const*);
static void assign_s(String*, String const*);
static void append_s(String*, String const*);
static void append_c(String*, char const*);

void StringInit(String *this, char const *s)
{
  if (s)
    this->str = strdup(s);
  else
    this->str = NULL;
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
  this->append_c = &append_c;
  this->append_s = &append_s;
}

void StringDestroy(String *this)
{
  if (this->str)
    free(this->str);
  memset(this, 0, sizeof(String));
}

static void assign_s(struct string *this, String const *str)
{
  assign_c(this, str->str);
}

static void assign_c(String *this, char const *s)
{
  StringDestroy(this);
  StringInit(this, s);
}

static void append_s(String *this, String const *ap)
{
  append_c(this, ap->str);

}

static void append_c(String *this, char const *ap)
{
  if (ap)
    {
      this->str = realloc(this->str, ((strlen(ap) + strlen(this->str) + 2) * sizeof(char)));
      strcat(this->str, ap);
    }
}
