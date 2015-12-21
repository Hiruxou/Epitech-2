/*
** mul_div.c for  in /home/nicolascharvoz/rendu/piscine_cpp_d02m/ex00
**
** Made by NicolasCharvoz
** Login   <nicolascharvoz@epitech.net>
**
** Started on  Thu Jan  8 09:16:57 2015 NicolasCharvoz
** Last update Thu Jan  8 09:28:06 2015 NicolasCharvoz
*/

#include <stdio.h>

void add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void add_mul_2param(int *first, int *second)
{
  int tmp = *first;

  *first = *first + *second;
  *second = tmp * *second;
}
