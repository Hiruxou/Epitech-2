/*
** pyramid.c for  in /home/charvo_a/rendu/piscine_cpp_d01/ex05
** 
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Wed Jan  7 17:05:35 2015 Charvoz Nicolas
** Last update Wed Jan  7 17:13:39 2015 Charvoz Nicolas
*/

#include <stdio.h>
#include <stdlib.h>

int     pyramid_path(int size, int **map)
{
  int	i;
  int	j;

  i = 0;
  j = size - 1;
  if (size == 1)
    return (map[0][0]);
  while (j >= 0)
    {
      i = 0;
      while (i + 1 <= size)
	{
	  if (map[j + 1][i] <= map[j + 1][i + 1])
	    {
	      map[j][i] += map[j + 1][i];
	    }
	  else
	    map[j][i] += map[j + 1][i + 1];
	  i++;
	}
      size--;
      j--;
    }
  return (map[0][0]);
}
