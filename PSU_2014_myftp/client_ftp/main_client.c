/*
** client.c for  in /home/nicolaschr/TP/ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Mar  5 15:22:24 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:54:01 2015 Nicolas Charvoz
*/

#include "client.h"

int		main(int argc, char **argv)
{
  t_client	*c;

  c = xmalloc(sizeof(*c));
  init_struct(c);
  if (argc >= 3)
    {
      c->servport = atoi(argv[2]);
      strcpy(c->server, argv[1]);
    }
  else if (argc == 2)
    {
      c->servport = atoi(argv[1]);
      strcpy(c->server, SERVER);
    }
  else
    {
      c->servport = 4242;
      strcpy(c->server, SERVER);
    }
  create_socket(c);
  init_host(c, argv);
  connect_to_server(c);
  read_write_client(c);
  close(c->sd);
  return (0);
}
