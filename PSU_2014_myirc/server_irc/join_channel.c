/*
** join_channel.c for join_channel in /home/antgar/rendu/PSU_2014_myirc/server_irc
**
** Made by Antoine Garcia
** Login   <antgar@epitech.net>
**
** Started on  Fri Apr 10 06:53:59 2015 Antoine Garcia
** Last update Fri Apr 10 08:59:41 2015 Antoine Garcia
*/

#include "server.h"

void	join_channel(t_server *s, t_client *c)
{
  t_client	*list;
  char		buffer[4096];

  list = s->clients;
  snprintf(buffer, 4096, "New user has joined the channel\n");
  while (list)
    {
      if (!strcmp(c->chan, list->chan) && (list != c))
	{
	  send(list->c_fd, buffer, 4096, 0);
	}
      list = list->next;
    }
}
