/*
** user.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/server_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Apr 15 17:22:44 2015 Nicolas Charvoz
** Last update Thu Apr 16 11:33:10 2015 Nicolas Charvoz
*/

#include "server.h"

int	user_irc(t_server *s, t_client *c)
{
  char buf[4096];

  bzero(buf, 4096);
  if (!(s->args[1]) || !(s->args[2]) || !(s->args[3]) || !(s->args[4]))
    {
      send(c->c_fd, "ERR_NEEDMOREPARAMS\r\n",
	   strlen("ERR_NEEDMOREPARAMS\r\n"), 0);
      return (0);
    }
  sprintf(buf, ":127.0.0.1:4242 001 user :Welcome to the Nicolas \
Internet Relay Chat Network user\r\n");
  send(c->c_fd, buf, strlen(buf), 0);
  bzero(buf, 4096);
  sprintf(buf, ":127.0.0.1:4242 002 user : Thanks to Epitech \
(www.epitech.eu) for sponsoring this server!\r\n");
  send(c->c_fd, buf, strlen(buf), 0);
  return (0);
}
