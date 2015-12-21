/*
** command2.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 17 11:32:57 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:54:50 2015 Nicolas Charvoz
*/

#include "server.h"

int	put_server(t_server *s)
{
  FILE	*file;
  int	size;

  if (s->args[1])
    {
      size = atoi(s->args[2]);
      printf("Size of the file to save :  = %d o\n", size);
      if ((file = fopen(s->args[1], "wb")) == NULL)
	{
	  perror("PUT ");
	  return (0);
	}
      write(s->i, c150, strlen(c150));
      read_inf(s->i, size, file);
      write(s->i, c200, strlen(c200));
      fclose(file);
    }
  return (0);
}

int pwd_server(t_server *s)
{
  char          *buffer;

  if (system("pwd > /tmp/ftp_tmp") == -1)
    {
      write(s->i, c202, strlen(c202));
      return (0);
    }
  buffer = read_file("/tmp/ftp_tmp");
  if (buffer)
    {
      printf("%s%s%s\n LIST\n %s%s\n%s%s", KGRN, c150,
	     RESET, KGRN, c200, c226, RESET);
      write(s->i, buffer, strlen(buffer));
    }
  free(buffer);
  return (0);
}

int quit_server(t_server *s)
{
  write(s->i, "QUIT RECEIVED\n", strlen("QUIT RECEIVED\n"));
  return (0);
}

int noop_server(t_server *s)
{
  write(s->i, c202, strlen(c202));
  return (0);
}
