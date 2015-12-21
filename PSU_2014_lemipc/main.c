/*
** main.c for main in /home/garcia_t/rendu/PSU_2014_lemipc
** 
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Mon Mar  2 11:52:53 2015 antoine garcia
** Last update Sun Mar  8 19:00:11 2015 antoine garcia
*/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <strings.h>
#include "lemipc.h"

static void check_options(int ac, char **av, t_lemipc *lemipc)
{
  char	optstring[] = "t:l";
  char	c;

  lemipc->player.team = 1;
  while ((c = getopt(ac, av, optstring)) != EOF)
    {
      if (c == 't')
	lemipc->player.team = atoi(optarg);
    }
}

int	main(int ac, char **av)
{
  t_lemipc	lemipc;

  srand(time(NULL));
  bzero(&lemipc, sizeof(t_lemipc));
  check_options(ac, av, &lemipc);
  init_lemipc(&lemipc);
  launch_game(&lemipc);
  printf("I Quit correctly\n");
  return (0);
}
