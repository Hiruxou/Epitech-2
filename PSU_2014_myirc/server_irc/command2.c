/*
** command2.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/client_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Apr  8 15:35:57 2015 Nicolas Charvoz
** Last update Thu Apr 16 13:17:04 2015 Nicolas Charvoz
*/

#include "server.h"

int		users_irc(t_server *s, t_client *c)
{
  t_client	*list;
  char		*delim;

  if (c->chan[0] == '\0')
    {
      send(c->c_fd, "No channel\n", strlen("No channel\n"), 0);
      return (0);
    }
  delim = strdup("--------------\n");
  list = s->clients;
  send(c->c_fd, delim, strlen(delim), 0);
  while (list)
    {
      if (!strcmp(list->chan, c->chan))
	{
	  send(c->c_fd, list->name, strlen(list->name), 0);
	  send(c->c_fd, "\n", strlen("\n"), 0);
	}
      list = list->next;
    }
  send(c->c_fd, delim, strlen(delim), 0);
  return (0);
}

int	private_msg_irc(t_server *s, t_client *c)
{
  t_client	*list;
  char		buf[4096];

  list = s->clients;
  if (s->args[1][0] == '#')
    {
      msg_irc(s, c);
      return (0);
    }
  if (s->args[1] && s->args[2])
    {
      while (list)
	{
	  if (!strcmp(s->args[1], list->name))
	    {
	      sprintf(buf, "Private message from %s : %s\r\n", c->name, s->buf);
	      send(list->c_fd, buf, strlen(buf), 0);
	    }
	  list = list->next;
	}
    }
  return (0);
}

int	send_file_irc(t_server *s, t_client *c)
{
  (void)c;
  (void)s;
  return (0);
}

int	accept_file_irc(t_server *s, t_client *c)
{
  (void)c;
  (void)s;
  return (0);
}

int	msg_irc(t_server *s, t_client *c)
{
  t_client	*list;
  char		buffer[4096];

  list = s->clients;
  bzero(buffer, 4096);
  while (list)
    {
      if (list->chan[0] == '\0')
	return (0);
      if (!strcmp(list->chan, c->chan))
	{
	  snprintf(buffer, 4096, "%s!~1@127.0.0.1 PRIVMSG #%s :%s\r\n",
		   c->name, c->chan, s->buf);
	  send(list->c_fd, buffer, 4096, 0);
	}
      list = list->next;
    }
  return (0);
}
