/*
** command.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/client_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Apr  8 15:35:00 2015 Nicolas Charvoz
** Last update Thu Apr 16 11:35:35 2015 Nicolas Charvoz
*/

#include "server.h"

int server_irc(t_server *s, t_client *c)
{
  char	buf[4096];

  bzero(buf, 4096);
  if (!(s->args[1]) || !(s->args[2]) || !(s->args[3]))
    {
      send(c->c_fd, "ERR_ALREADYREGISTRED\r\n",
	   strlen("ERR_ALREADYREGISTRED\r\n"), 0);
      return (0);
    }
  sprintf(buf, ":127.0.0.1:4242 001 user :Welcome to the Nicolas \
Internet Relay Chat Network user\r\n");
  send(c->c_fd, buf, strlen(buf), 0);
  return (0);
}

int nick_irc(t_server *s, t_client *c)
{
  char	buf[4096];

  bzero(buf, 4096);
  if (s->args[1] == NULL || !strcmp("(null)", s->args[1]))
    send(c->c_fd, "No nickname\n", strlen("No nickname\n"), 0);
  else if (!strcmp(s->args[1], c->name))
    send(c->c_fd, "You already have this nickname\n",
	 strlen("You already have this nickname\n"), 0);
  else
    {
      change_nickname(s, c, s->args[1]);
      sprintf(buf, ":user MODE user :+i\r\n");
      send(c->c_fd, buf, strlen(buf), 0);
    }
  return (0);
}

int list_irc(t_server *s, t_client *c)
{
  (void)c;
  (void)s;
  return (0);
}

int join_irc(t_server *s, t_client *c)
{
  char	buf[4096];

  bzero(buf, 4096);
  if (s->args[1] == NULL)
    send(c->c_fd, "No channel\n", strlen("No channel\n"), 0);
  else if (!strcmp("(null)", s->args[1]))
    send(c->c_fd, "No channel\n", strlen("No channel\n"), 0);
  else if (!strcmp(s->args[1], c->chan))
    printf("You are already in this channel\n");
  else
    {
      snprintf(c->chan, 4096, "%s", s->args[1]);
      join_channel(s, c);
      sprintf(buf, ":127.0.0.1:4242 003 user :RPL_TOPIC\r\n");
      send(c->c_fd, buf, strlen(buf), 0);
      bzero(buf, 4096);
      sprintf(buf, ":127.0.0.1:4242 003 user :RPL_NAMEREPLY\r\n");
      send(c->c_fd, buf, strlen(buf), 0);
    }
  return (0);
}

int part_irc(t_server *s, t_client *c)
{
  char	buffer[4096];
  t_client	*list;
  char	success[4096];

  bzero(buffer, 4096);
  if (s->args[1] == NULL || !strcmp("(null)", s->args[1]) ||
      strcmp(s->args[1], c->chan))
      send(c->c_fd, ":127.0.0.1:4242 003 user :ERR_NOSUCHCHANNEL\r\n",
	   strlen(":127.0.0.1:4242 003 user :ERR_NOSUCHCHANNEL\r\n"), 0);
  else
    {
      list = s->clients;
      snprintf(buffer, 4096, "%s has quit the channel\n", c->name);
      while (list)
	{
	  if (!strcmp(list->chan, c->chan) && (list != c))
	    send(list->c_fd, buffer, strlen(buffer), 0);
	  list = list->next;
	}
      sprintf(success, "You have successfully quit the channel\n");
      send(c->c_fd, success, strlen(success), 0);
      bzero(c->chan, 4096);
    }
  return (0);
}
