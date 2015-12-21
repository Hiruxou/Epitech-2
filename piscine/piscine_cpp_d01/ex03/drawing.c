/*
** drawing.c for  in /home/charvo_a/rendu/piscine_cpp_d01/ex03
**
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Jan  7 14:44:55 2015 Charvoz Nicolas
** Last update Thu Jan  8 08:59:38 2015 NicolasCharvoz
*/

#include "drawing.h"

void		draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  img[orig->x + i][orig->y + j] = color;
	  j++;
	}
      i++;
    }
}
