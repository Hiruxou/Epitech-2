/*
** command2.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 17 11:50:10 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:40:17 2015 Nicolas Charvoz
*/

#include "client.h"

int		get_ftp(t_client *c)
{
  if (c->username != NULL)
    write(c->sd, "RETR\n", strlen("RETR\n"));
  else
    write(c->sd, "NOOP\n", strlen("NOOP\n"));
  return (0);
}

int		put_ftp(t_client *c)
{
  char		final[4096];
  int		size;
  char		*buffer;

  bzero(final, 4096);
  if (!(c->args[1]))
    {
      printf("1File does not exist\n");
      write(c->sd, "NOOP\n", strlen("NOOP\n"));
      return (0);
    }
  if (file_exists(c->args[1]) == 0)
    {
      buffer = read_file(c->args[1], &size);
      sprintf(final, "%s %s %d", "STOR", c->args[1], size);
      write(c->sd, final, strlen(final));
      write(c->sd, buffer, size);
    }
  else
    {
      printf("2File does not exist\n");
      write(c->sd, "NOOP\n", strlen("NOOP\n"));
    }
  free(buffer);
  return (0);
}

int quit_ftp(t_client *c)
{
  printf("Thanks for using charZilla\n");
  close(c->sd);
  write(c->sd, "QUIT\n", strlen("QUIT\n"));
  exit(0);
  return (0);
}

int clear_client(t_client *c)
{
  system("clear");
  write(c->sd, "CLEAR\n", strlen("CLEAR\n"));
  return (0);
}

int noop_ftp(t_client *c)
{
  write(c->sd, "NOOP\n", strlen("NOOP\n"));
  return (0);
}
