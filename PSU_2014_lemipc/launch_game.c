/*
** launch_game.c for launch_game in /home/garcia_t/rendu/PSU_2014_lemipc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Mar  2 20:23:27 2015 antoine garcia
** Last update Sun Mar  8 21:36:34 2015 antoine garcia
*/

#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include "lemipc.h"

char	g_check = 1;

void	catch_signal(int sig)
{
  sig = sig;
  g_check = 0;
}

int	count_players(t_lemipc *lemipc)
{
  int	y;
  int	x;
  int	nb_players;

  y = 0;
  nb_players = 0;
  while (y < MAX)
    {
      x = 0;
      while (x < MAX)
	{
	  if (lemipc->game->map[y][x] != 0)
	    nb_players++;
	  x++;
	}
      y++;
    }
  return (nb_players);
}

static void	init_player(t_lemipc *lemipc)
{
  int	x;
  int	y;

  x = rand() % MAX;
  y = rand() % MAX;
  if (lemipc->game->map[y][x] == 0)
    {
      lemipc->player.pos.x = x;
      lemipc->player.pos.y = y;
      lemipc->game->map[y][x] = lemipc->player.team;
    }
  else
    init_player(lemipc);
}

static int player_loop(t_lemipc *lemipc)
{
  while (g_check)
    {
      printf("still Alive !\n");
      lock_sem(lemipc->game->sem_id);
      if (check_death(lemipc) == 1)
      	return (0);
      move_random(lemipc);
      usleep(600000);
      unlock_sem(lemipc->game->sem_id);
    }
  return (1);
}

int	launch_game(t_lemipc *lemipc)
{
  signal(SIGINT, catch_signal);
  srand(time(NULL));
  lock_sem(lemipc->game->sem_id);
  init_player(lemipc);
  unlock_sem(lemipc->game->sem_id);
  player_loop(lemipc);
  lemipc->game->map[lemipc->player.pos.y][lemipc->player.pos.x] = 0;
  if (count_players(lemipc) == 0)
    {
      printf("Winner is team %d\n", lemipc->player.team);
      free_ipcs(lemipc);
    }
  return (0);
}
