/*
** add.c for  in /home/nicolascharvoz/rendu/piscine_cpp_d02m/ex04
**
** Made by NicolasCharvoz
** Login   <nicolascharvoz@epitech.net>
**
** Started on  Thu Jan  8 12:41:51 2015 NicolasCharvoz
** Last update Thu Jan  8 19:22:03 2015 Nicolas Charvoz
*/

#include "castmania.h"

int normal_add(int a, int b)
{
  return (a + b);
}

int absolute_add(int a, int b)
{
  if (a < 0)
    a = a * (-1);
  if (b < 0)
    b = b * (-1);
  return (a + b);
}

void exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    {
      operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
    }
  else if (operation->add_type == ABSOLUTE)
    {
      operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
    }
}
