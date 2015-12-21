/*
** String.h for  in /home/nicolaschr/rendu/piscine_cpp_d03/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:57:15 2015 Nicolas Charvoz
** Last update Fri Jan  9 16:01:46 2015 Nicolas Charvoz
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
  int (*compare_s)(struct string*, const struct string*);
  int (*compare_c)(struct string*, char const*);
  size_t (*copy)(struct string*, char*, size_t, size_t);
  char const *(*c_str)(struct string*);
  int (*empty)(struct string*);
  int (*find_s)(struct string*, const struct string*, size_t);
  int (*find_c)(struct string*, char const*, size_t);
  void (*insert_c)(struct string*, size_t, char const*);
  void (*insert_s)(struct string*, size_t, struct string const*);
  int (*to_int)(struct string*);
  struct string *(*split_s)(struct string*, char);
  char **(*split_c)(struct string*, char);
  void (*aff)(struct string *);
}String;

void StringInit(String*, const char*);
void StringDestroy(String*);

#endif
