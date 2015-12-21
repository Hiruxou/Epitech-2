/*
** check_death.c for check_death in /home/garcia_t/rendu/PSU_2014_lemipc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Thu Mar  5 12:49:32 2015 antoine garcia
** Last update Sun Mar  8 11:59:30 2015 Nicolas Charvoz
*/

#include "lemipc.h"

int g_flag = 0;

int	check_death(t_lemipc *lemipc)
{
  int	xfirst;
  int	yfirst;
  int	xlast;
  int	ylast;
  int	tmp;

  xfirst = ((lemipc->player.pos.x - 1) <= 0 ? 0 : lemipc->player.pos.x - 1);
  yfirst = ((lemipc->player.pos.y - 1) <= 0 ? 0 : lemipc->player.pos.y - 1);
  tmp = yfirst;
  xlast = ((lemipc->player.pos.x + 1) >= MAX ? MAX : lemipc->player.pos.x + 1);
  ylast = ((lemipc->player.pos.y + 1) >= MAX ? MAX : lemipc->player.pos.y + 1);
  while (xfirst <= xlast)
    {
      yfirst = tmp;
      while (yfirst <= ylast)
  	{
  	  if (lemipc->game->map[yfirst][xfirst] != 0 &&
  	      lemipc->game->map[yfirst][xfirst] != lemipc->player.team)
  	    g_flag += 1;
  	  yfirst++;
  	}
      xfirst++;
    }
  return (g_flag >= 2 ? 1 : 0);
}
