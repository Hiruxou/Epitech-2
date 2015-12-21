/*
** xmalloc.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sun Mar 22 11:45:24 2015 Nicolas Charvoz
** Last update Sun Mar 29 17:51:37 2015 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>

void    *xmalloc(int size)
{
  void  *s;

  if ((s = malloc(size)) == NULL)
    {
      printf("Problem on malloc\n");
      exit(-1);
    }
  return (s);
}
