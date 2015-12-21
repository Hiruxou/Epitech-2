/*
** move.c for move in /home/garcia_t/rendu/PSU_2014_lemipc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Fri Mar  6 12:54:51 2015 antoine garcia
** Last update Sun Mar  8 21:29:31 2015 antoine garcia
*/

#include "lemipc.h"

int	move_random(t_lemipc *lemipc)
{
  int	x;
  int	y;
  int	copy_x;
  int	copy_y;

  copy_x = lemipc->player.pos.x;
  copy_y = lemipc->player.pos.y;
  x = copy_x + (rand() % 3 - 1);
  y = copy_y
    + (x == copy_x ? rand() % 2 ? -1 : 1 : 0);
  if ((lemipc->player.pos.y == 0 && y == -1) ||
      (lemipc->player.pos.x == 0 && x == -1))
    move_random(lemipc);
  else if (lemipc->game->map[y][x] == 0 && x >= 0 && x < MAX
	   && y < MAX && y >= 0)
    {
      lemipc->game->map[lemipc->player.pos.y][lemipc->player.pos.x] = 0;
      lemipc->player.pos.x = x;
      lemipc->player.pos.y = y;
      lemipc->game->map[y][x] = lemipc->player.team;
    }
  else
    move_random(lemipc);
  return (0);
}
