/*
** mem_ptr.c for  in /home/nicolascharvoz/rendu/piscine_cpp_d02m/ex01
**
** Made by NicolasCharvoz
** Login   <nicolascharvoz@epitech.net>
**
** Started on  Thu Jan  8 09:29:12 2015 NicolasCharvoz
** Last update Thu Jan  8 09:50:39 2015 NicolasCharvoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void add_str(char *str1, char *str2, char **res)
{
  char *tmp;

  if ((tmp = malloc((strlen(str1) + strlen(str2) + 2) * sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  tmp = strcat(tmp, str1);
  tmp = strcat(tmp, str2);
  *res = tmp;
}

void add_str_struct(t_str_op *str_op)
{
  char *tmp;

  if ((tmp = malloc((strlen(str_op->str1) + strlen(str_op->str2) + 2) * sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  tmp = strcat(tmp, str_op->str1);
  tmp = strcat(tmp, str_op->str2);
  str_op->res = tmp;
}
