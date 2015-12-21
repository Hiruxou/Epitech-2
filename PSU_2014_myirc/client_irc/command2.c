/*
** command2.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/client_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Apr  8 15:35:57 2015 Nicolas Charvoz
** Last update Thu Apr 16 11:40:01 2015 Nicolas Charvoz
*/

#include "client.h"

int	users_irc(t_client *c)
{
  char	final[4096];

  bzero(final, 4096);
  sprintf(final, "NAMES\n");
  send(c->sd, final, strlen(final), 0);
  return (0);
}

int	private_msg_irc(t_client *c)
{
  char	final[4096];

  bzero(final, 4096);
  sprintf(final, "PRIVMSG %s %s\n", c->args[1], c->args[2]);
  send(c->sd, final, strlen(final), 0);
  return (0);
}

int	send_file_irc(t_client *c)
{
  char	final[4096];

  bzero(final, 4096);
  sprintf(final, "SEND_FILE %s\n", c->args[1]);
  send(c->sd, final, strlen(final), 0);
  return (0);
}

int	accept_file_irc(t_client *c)
{
  char	final[4096];

  bzero(final, 4096);
  sprintf(final, "ACCEPT_FILE %s\n", c->args[1]);
  send(c->sd, final, strlen(final), 0);
  return (0);
}

int	msg_irc(t_client *c)
{
  send(c->sd, c->buf, strlen(c->buf), 0);
  return (0);
}
