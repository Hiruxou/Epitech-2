/*
** init_client.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 23:16:04 2015 Nicolas Charvoz
** Last update Mon Apr 13 16:46:08 2015 Nicolas Charvoz
*/

#include "client.h"

void	create_socket(t_client *c)
{
  if ((c->sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      perror("Client-socket() error");
      exit(-1);
    }
  else
    printf("Client-socket() OK\n");
}

void	init_host(t_client *c, char **argv)
{
  memset(&(c->serveraddr), 0x00, sizeof(struct sockaddr_in));
  c->serveraddr.sin_family = AF_INET;
  c->serveraddr.sin_port = htons(c->servport);
  if ((c->serveraddr.sin_addr.s_addr = inet_addr(c->server)) ==
     (unsigned long)INADDR_NONE)
    {
      c->hostp = gethostbyname(c->server);
      if (c->hostp == (struct hostent *)NULL)
        {
          printf("HOST NOT FOUND --> ");
          printf("h_errno = %d\n", h_errno);
          printf("---This is a client program---\n");
          printf("Command usage: %s <server name or IP>\n", argv[0]);
          close(c->sd);
          exit(-1);
        }
      memcpy(&(c->serveraddr).sin_addr, c->hostp->h_addr_list[0],
	     sizeof(c->serveraddr.sin_addr));
    }
}

void	connect_to_server(t_client *c)
{
  if ((c->rc = connect(c->sd, (struct sockaddr *)&(c->serveraddr),
		      sizeof(c->serveraddr))) < 0)
    {
      perror("Client-connect() error");
      close(c->sd);
      exit(-1);
    }
  else
    printf("Connection established...\n");
}

void	read_write_client(t_client *c)
{
  while (42)
    {
      bzero(c->buf, 4096);
      fflush(stdout);
      loop_client(c);
    }
}
