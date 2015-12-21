/*
** interpret_cmd.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Mar 12 13:39:18 2015 Nicolas Charvoz
** Last update Thu Apr  9 11:50:10 2015 Nicolas Charvoz
*/

#include "client.h"

void	init_cmd(int(**cmd)(t_client *client))
{
  int	i;

  i = 0;
  cmd[i++] = &server_irc;
  cmd[i++] = &nick_irc;
  cmd[i++] = &list_irc;
  cmd[i++] = &join_irc;
  cmd[i++] = &part_irc;
  cmd[i++] = &users_irc;
  cmd[i++] = &private_msg_irc;
  cmd[i++] = &send_file_irc;
  cmd[i++] = &accept_file_irc;
  cmd[i++] = &msg_irc;
}

char	**init_tram()
{
  char	**tab;
  int	i;

  i = 0;
  tab = xmalloc(SIZE_OF_TAB_C * sizeof(char*));
  tab[i++] = "/server";
  tab[i++] = "/nick";
  tab[i++] = "/list";
  tab[i++] = "/join";
  tab[i++] = "/part";
  tab[i++] = "/users";
  tab[i++] = "/msg";
  tab[i++] = "/send_file";
  tab[i++] = "/accept_file";
  tab[i++] = NULL;
  return (tab);
}

void print_tab(char **tab)
{
  int i = 0;

  while (tab[i])
    printf("%s\n", tab[i++]);
}

void	exec_cmd(t_client *c, int mode)
{
  int	(*cmd[SIZE_OF_TAB_C])(t_client *client);
  int	i;
  char	**tab;

  i = 0;
  init_cmd(cmd);
  tab = init_tram();
  if (mode == 1)
    {
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
  else
    {
      msg_irc(c);
      return;
    }
}
