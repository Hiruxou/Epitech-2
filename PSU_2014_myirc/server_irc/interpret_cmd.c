/*
** interpret_cmd.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Mar 12 13:39:18 2015 Nicolas Charvoz
** Last update Wed Apr 15 17:22:35 2015 Nicolas Charvoz
*/

#include "server.h"

void	init_cmd(int(**cmd)(t_server *server, t_client *c))
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
  cmd[i++] = &user_irc;
  cmd[i++] = &msg_irc;
}

char	**init_tram()
{
  char	**tab;
  int	i;

  i = 0;
  tab = xmalloc(11 * sizeof(char*));
  tab[i++] = "SERVER";
  tab[i++] = "NICK";
  tab[i++] = "LIST";
  tab[i++] = "JOIN";
  tab[i++] = "PART";
  tab[i++] = "NAMES";
  tab[i++] = "PRIVMSG";
  tab[i++] = "SEND_FILE";
  tab[i++] = "ACCEPT_FILE";
  tab[i++] = "USER";
  tab[i++] = NULL;
  return (tab);
}

void print_tab(char **tab)
{
  int i = 0;

  while (tab[i])
    printf("%s\n", tab[i++]);
}

void	exec_cmd(t_server *s, int mode, t_client *c)
{
  int	(*cmd[11])(t_server *server, t_client *c);
  int	i;
  char	**tab;

  i = 0;
  init_cmd(cmd);
  tab = init_tram();
  if (mode == 1)
    {
      while (tab[i])
	{
	  if (strcmp(tab[i], s->args[0]) == 0)
	    {
	      cmd[i](s, c);
	      return;
	    }
	  i++;
	}
      cmd[i](s, c);
    }
  else
    {
      msg_irc(s, c);
      return;
    }
}
