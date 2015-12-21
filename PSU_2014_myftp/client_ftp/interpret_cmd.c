/*
** interpret_cmd.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Mar 12 13:39:18 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:52:21 2015 Nicolas Charvoz
*/

#include "client.h"

void	init_cmd(int(**cmd)(t_client *client))
{
  int	i;

  i = 0;
  cmd[i++] = &user_ftp;
  cmd[i++] = &ls_ftp;
  cmd[i++] = &lls_ftp;
  cmd[i++] = &cd_ftp;
  cmd[i++] = &lcd_ftp;
  cmd[i++] = &get_ftp;
  cmd[i++] = &put_ftp;
  cmd[i++] = &pwd_ftp;
  cmd[i++] = &lpwd_ftp;
  cmd[i++] = &quit_ftp;
  cmd[i++] = &clear_client;
  cmd[i++] = &noop_ftp;
}

char	**init_tram()
{
  char	**tab;
  int	i;

  i = 0;
  tab = xmalloc(SIZE_OF_TAB_C * sizeof(char*));
  tab[i++] = "user";
  tab[i++] = "ls";
  tab[i++] = "lls";
  tab[i++] = "cd";
  tab[i++] = "lcd";
  tab[i++] = "get";
  tab[i++] = "put";
  tab[i++] = "pwd";
  tab[i++] = "lpwd";
  tab[i++] = "quit";
  tab[i++] = "clear";
  tab[i++] = NULL;
  return (tab);
}

void	exec_cmd(t_client *c)
{
  int	(*cmd[12])(t_client *client);
  int	i;
  char	**tab;

  i = 0;
  init_cmd(cmd);
  tab = init_tram();
  while (tab[i])
    {
      if (strcmp(tab[i], c->args[0]) == 0)
	{
	  cmd[i](c);
	  return;
	}
      i++;
    }
  cmd[i](c);
}
