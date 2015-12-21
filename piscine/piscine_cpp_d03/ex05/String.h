/*
** String.h for  in /home/nicolaschr/rendu/piscine_cpp_d03/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:57:15 2015 Nicolas Charvoz
** Last update Fri Jan  9 12:07:23 2015 Nicolas Charvoz
*/

#ifndef _STRING_H_
#define _STRING_H_

#include <string.h>

typedef struct string
{
  char *str;
  void (*assign_s)(struct string*,struct string const*);
  void (*assign_c)(struct string*, char const*);
  void (*append_s)(struct string*, struct string const*);
  void (*append_c)(struct string*, char const*);
  char (*at)(struct string*, size_t);
  void (*clear)(struct string*);
  int (*size)(struct string*);
}String;

void StringInit(String*, const char*);
void StringDestroy(String*);

#endif
