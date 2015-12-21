/*
** String.c for  in /home/nicolaschr/rendu/piscine_cpp_d03/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:58:38 2015 Nicolas Charvoz
** Last update Fri Jan  9 13:26:12 2015 Nicolas Charvoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "String.h"

static void assign_c(String*, char const*);
static void assign_s(String*, String const*);
static void append_s(String*, String const*);
static void append_c(String*, char const*);
static char at(String *this, size_t pos);
static void clear(String *this);
static int size(String *this);
static int compare_s(String *this, const String *str);
static int compare_c(String *this, char const* str);
static size_t copy(String *this, char *s, size_t n, size_t pos);
static char const *c_str(String*);
static int empty(String *this);

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
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
  this->compare_c = &compare_c;
  this->compare_s = &compare_s;
  this->copy = &copy;
  this->c_str = &c_str;
  this->empty = &empty;
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

static char at(String *this, size_t pos)
{
  if ((pos <= strlen(this->str) - 1))
    return (this->str[pos]);
  return (-1);
}

static void clear(String *this)
{
  if (this->str)
    memset(this->str, 0, strlen(this->str));
}

static int size(String *this)
{
  if (this->str)
    return (strlen(this->str));
  return (-1);
}

static int compare_s(String *this, const String *str)
{
  return (compare_c(this, str->str));
}

static int compare_c(String *this, char const* str)
{
  return (strcmp(this->str, str));
}

static size_t copy(String *this, char *s, size_t n, size_t pos)
{
  int i = 0;

  if (this && s)
    {
      while (n-- > 0 && pos < strlen(this->str))
	s[i++] = this->str[pos++];
      s[i] = '\0';
    }
  return (i);
}

static char const *c_str(String *this)
{
  return this->str;
}

static int empty(String *this)
{
  if (size(this) > 0)
    return (-1);
  return (1);
}
