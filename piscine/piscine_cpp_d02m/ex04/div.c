/*
** div.c for  in /home/nicolascharvoz/rendu/piscine_cpp_d02m/ex04
**
** Made by NicolasCharvoz
** Login   <nicolascharvoz@epitech.net>
**
** Started on  Thu Jan  8 11:38:07 2015 NicolasCharvoz
** Last update Thu Jan  8 12:58:59 2015 NicolasCharvoz
*/

#include "castmania.h"

int integer_div(int a, int b)
{
  if (b)
    return (a / b);
  return (0);
}

float decimale_div(int a, int b)
{
  if (b)
    return (a / (float)b);
  return (0);
}

void exec_div(t_div *operation)
{
  if (operation->div_type == INTEGER)
    {
      ((t_integer_op*) operation->div_op)->res = integer_div(((t_integer_op*) operation->div_op)->a, ((t_integer_op*) operation->div_op)->b);
    }
  else if (operation->div_type == DECIMALE)
    {
      ((t_integer_op*) operation->div_op)->res = decimale_div(((t_integer_op*) operation->div_op)->a, ((t_integer_op*) operation->div_op)->b);
    }
}
