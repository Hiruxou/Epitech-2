/*
** tab_to_2dtab.c for  in /home/nicolascharvoz/rendu/piscine_cpp_d02m/ex02
**
** Made by NicolasCharvoz
** Login   <nicolascharvoz@epitech.net>
**
** Started on  Thu Jan  8 09:55:11 2015 NicolasCharvoz
** Last update Thu Jan  8 10:19:40 2015 NicolasCharvoz
*/

#include <stdlib.h>
#include <stdio.h>

void tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int **tmp;
  int i;
  int j;
  int k;

  k = 0;
  i = 0;
  tmp = malloc((length) * sizeof(int*));
  while (i < length)
    {
      tmp[i] = malloc((width) * sizeof(int));
      j = 0;
      while (j < width)
	{
	  tmp[i][j] = tab[k];
	  j++;
	  k++;
	}
      i++;
    }
  *res = tmp;
}
