/*
** init_client.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 23:16:04 2015 Nicolas Charvoz
** Last update Sun Mar 29 18:03:07 2015 Nicolas Charvoz
*/

#include "client.h"

char	*g_server;
int	g_servport;
char	*g_name;

void	handler_ctrl_c(int sig)
{
  sig = sig;
  printf("\n");
  printf("\e[1;33m%s@%s:%d> \e[0m", g_name, g_server, g_servport);
  fflush(stdout);
}

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
  g_server = strdup(c->server);
  g_name = strdup("user");
  while (42)
    {
      bzero(c->buf, 4096);
      g_servport = c->servport;
      printf("\n");
      printf("\e[1;33m%s@%s:%d> \e[0m", g_name, g_server, g_servport);
      fflush(stdout);
      signal(SIGINT, handler_ctrl_c);
      c->rc = read(0, c->buf, 4096);
      if (c->buf[0] != '\n' && c->rc != 0 && c->buf[0] != EOF)
	{
	  parser(c->buf, c);
	  exec_cmd(c);
	  if (c->username != NULL)
	    g_name = strdup(c->username);
	  c->rc = read(c->sd, c->buf, 4096);
	  write(1, c->buf, c->rc);
	  free_tab(c);
	}
    }
}
