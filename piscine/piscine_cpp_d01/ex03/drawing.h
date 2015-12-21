/*
** drawing.h for  in /home/charvo_a/rendu/piscine_cpp_d01/ex03
**
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Jan  7 14:41:38 2015 Charvoz Nicolas
** Last update Thu Jan  8 00:22:53 2015 Nicolas
*/

#ifndef DRAWING_H_
#define DRAWING_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct		s_point
{
  unsigned int		x;
  unsigned int		y;
}			t_point;

void draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color);

#endif
