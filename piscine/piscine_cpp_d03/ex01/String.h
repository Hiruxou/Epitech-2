/*
** String.h for  in /home/nicolaschr/rendu/piscine_cpp_d03/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:57:15 2015 Nicolas Charvoz
** Last update Fri Jan  9 11:43:58 2015 Nicolas Charvoz
*/

#ifndef _STRING_H_
#define _STRING_H_

typedef struct string
{
  char *str;
  void (*assign_s)(struct string*,struct string const*);
  void (*assign_c)(struct string*, char const*);
}String;

void StringInit(String*, const char*);
void StringDestroy(String*);

#endif
