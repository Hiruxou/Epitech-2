/*
** command.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/client_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Apr  8 15:35:00 2015 Nicolas Charvoz
** Last update Thu Apr  9 11:51:33 2015 Nicolas Charvoz
*/

#include "client.h"

int server_irc(t_client *c)
{
  send(c->sd, "SERVER", strlen("SERVER"), 0);
  return (0);
}

int nick_irc(t_client *c)
{
  char final[4096];

  bzero(final, 4096);
  sprintf(final, "NICK %s\n", c->args[1]);
  send(c->sd, final, strlen(final), 0);
  return (0);
}

int list_irc(t_client *c)
{
  char final[4096];

  bzero(final, 4096);
  if (c->args[1])
    sprintf(final, "LIST %s\n", c->args[1]);
  else
    sprintf(final, "LIST\n");
  send(c->sd, final, strlen(final), 0);
  return (0);
}

int join_irc(t_client *c)
{
  char final[4096];

  bzero(final, 4096);
  sprintf(final, "JOIN %s\n", c->args[1]);
  send(c->sd, final, strlen(final), 0);
  return (0);
}

int part_irc(t_client *c)
{
  char final[4096];

  bzero(final, 4096);
  sprintf(final, "PART %s\n", c->args[1]);
  send(c->sd, final, strlen(final), 0);
  return (0);
}
