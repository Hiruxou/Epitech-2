/*
** utilis.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:38:51 2015 Nicolas Charvoz
** Last update Thu Apr 16 12:05:04 2015 Nicolas Charvoz
*/

#include "server.h"

void	init_socket(t_server *s)
{
  int	yes;

  yes = 1;
  FD_ZERO(&s->master);
  FD_ZERO(&s->read_fds);
  s->listener = xsocket(AF_INET, SOCK_STREAM, 0);
  printf("Server-socket() is OK ... \n");
  if (setsockopt(s->listener, SOL_SOCKET, SO_REUSEADDR, &yes,
		 sizeof(int)) == -1)
    {
      perror("Server-setsockopt() erro !");
      exit(1);
    }
  printf("Server-setsockopt() is OK ... \n");
}

void	bind_socket(t_server *s, int port)
{
  s->serveraddr.sin_family = AF_INET;
  s->serveraddr.sin_addr.s_addr = INADDR_ANY;
  s->serveraddr.sin_port = htons(port);
  memset(&(s->serveraddr.sin_zero), '\0', 8);
  xbind(s->listener, (struct sockaddr *)&(s->serveraddr),
	sizeof(s->serveraddr));
  printf("Server-bind() is OK ...\n");
}

void	accept_server(t_server *s, char **argv)
{
  t_client	*client;
  int		addrlen;

  addrlen = sizeof(struct sockaddr_in);
  client = push_back(&s->clients);
  if ((client->c_fd = accept(s->listener,
			     (struct sockaddr *)&(client->clientaddr),
			 (socklen_t*)&(addrlen))) == -1)
      perror("Server-accept() error !");
  else
    {
      printf("Server-accept() is OK...\n");
      FD_SET(client->c_fd, &(s->master));
      bzero(client->chan, 4096);
      s->nb_clients++;
      client->id = s->nb_clients;
      snprintf(client->name, 4096, "Anonymous%d", s->nb_clients);
      if (client->c_fd > s->fdmax)
	s->fdmax = client->c_fd;
      printf("%s: New connection from %s on socket %d\n", argv[0],
	     inet_ntoa(client->clientaddr.sin_addr), client->c_fd);
    }
}

t_client	*choose_client(int i, t_server *s, t_client *c)
{
  t_client	*tmp;

  tmp = s->clients;
  while (tmp)
    {
      if (tmp->c_fd == i)
	c = tmp;
      tmp = tmp->next;
    }
  return (c);
}

void		read_write_server(t_server *s, int i, char **argv)
{
  ssize_t	nbytes;
  t_client	*c;

  c = xmalloc(sizeof(*c));
  c = choose_client(i, s, c);
  s->buf = xmalloc(4096 * sizeof(char));
  memset(s->buf, '\0', 4096);
  if ((nbytes = recv(i, s->buf, 4095, 0)) <= 0)
    {
      if (nbytes == 0)
	printf("%s: socket %d hung up\n", argv[0], i);
      else
	perror("read() error!");
      close(i);
      FD_CLR(i, &(s->master));
    }
  else
    {
      printf("COMMAND: |%s|\r\n", s->buf);
      if (s->buf[0] == '\n' || s->buf[0] == EOF)
	return;
      parser(s->buf, s);
      exec_cmd(s, 1, c);
    }
  free(s->buf);
}
