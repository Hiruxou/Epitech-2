/*
** my_cd.c for  in /home/charvo_a/rendu/PSU_2013_minishell2/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun Mar  9 15:14:03 2014 Nicolas Charvoz
** Last update Sun Mar 22 11:14:44 2015 Nicolas Charvoz
*/

#include "server.h"

int	my_cd(char *arg, t_server *s)
{
  char  *home;

  home = s->home;
  if (!arg)
    {
      chdir(home);
      return (0);
    }
  else
    {
      if (chdir(arg) == -1)
	return (-1);
      return (0);
    }
  free(home);
}
