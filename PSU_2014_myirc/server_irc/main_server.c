/*
** server.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:25:19 2015 Nicolas Charvoz
** Last update Mon Apr 13 16:47:26 2015 Nicolas Charvoz
*/

#include "server.h"

void		loop_server(t_server *s, char **argv)
{
  int		i;

  while (42)
    {
      i = 0;
      s->read_fds = s->master;
      if (select(s->fdmax + 1, &(s->read_fds), NULL, NULL, NULL) == -1)
	{
	  perror("Server-select() error !");
	  exit(1);
	}
      printf("Server-select() is OK...\n");
      while (i <= s->fdmax)
	{
	  if (FD_ISSET(i, &(s->read_fds)))
	    {
	      if (i == s->listener)
		accept_server(s, argv);
	      else
		read_write_server(s, i, argv);
	    }
	  i++;
	}
    }
}

int		main(int argc, char **argv)
{
  t_server	*s;
  int		port;
  char		path[4096];

  getcwd(path, 4096);
  if (argc >= 2)
    port = atoi(argv[1]);
  else
    port = 4242;
  s = xmalloc(sizeof(*s));
  init_socket(s);
  bind_socket(s, port);
  xlisten(s->listener, 10);
  FD_SET(s->listener, &(s->master));
  s->fdmax = s->listener;
  s->clients = NULL;
  s->nb_clients = 0;
  loop_server(s, argv);
  return (0);
}
