/*
** main.c for main in /home/garcia_t/elcrypt
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Mar 14 11:22:49 2015 antoine garcia
** Last update Sun Mar 15 11:54:20 2015 Nicolas Charvoz
*/

#include <stdio.h>
#include "elcrypt.h"

int	main(int ac, char **av)
{
  t_opt	opt;

  if (ac > 9)
    {
      printf("Too much arguments.\n");
      return (-1);
    }
  else if (ac < 8)
    {
      printf("Usage : %s -e -f [src file] -o [dest file] -k [key]\n", av[0]);
      return (-1);
    }
  parse_argv(ac, &opt, av);
  init(&opt);
  return (0);
}
