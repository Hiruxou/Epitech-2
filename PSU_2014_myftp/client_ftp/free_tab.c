/*
** free_tab.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 17 00:53:41 2015 Nicolas Charvoz
** Last update Sun Mar 29 17:46:10 2015 Nicolas Charvoz
*/

#include "client.h"

void	free_tab(t_client *c)
{
  int	i;

  i = 0;
  while (c->args[i])
    {
      free(c->args[i]);
      i++;
    }
  free(c->args);
}
