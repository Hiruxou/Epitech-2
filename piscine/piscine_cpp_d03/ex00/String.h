/*
** String.h for  in /home/nicolaschr/rendu/piscine_cpp_d03/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:57:15 2015 Nicolas Charvoz
** Last update Fri Jan  9 11:43:25 2015 Nicolas Charvoz
*/

#ifndef _STRING_H_
#define _STRING_H_

typedef struct s_String
{
  char *str;
}String;

void StringInit(String*, const char*);
void StringDestroy(String*);

#endif
