/*
** loop_client.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/client_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sun Apr 12 17:51:18 2015 Nicolas Charvoz
** Last update Mon Apr 13 14:43:20 2015 Nicolas Charvoz
*/

#include "client.h"

void read_message_from_server(t_client *c)
{
  char sarah[4096];

  bzero(sarah, 4096);
  read(c->sd, sarah, 4095);
  write(1, sarah, strlen(sarah));
}

void		loop_client(t_client *c)
{
  FD_SET(0, &(c->read_fds));
  FD_SET(c->sd, &(c->read_fds));
  if (select(c->sd + 1, &(c->read_fds), NULL, NULL, NULL) == -1)
    {
      perror("Client-select() error ! ");
      exit(1);
    }
  if (FD_ISSET(c->sd, &(c->read_fds)))
    read_message_from_server(c);
  if (FD_ISSET(0, &(c->read_fds)))
    send_message(c);
}
