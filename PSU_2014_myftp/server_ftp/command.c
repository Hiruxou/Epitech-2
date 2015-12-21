/*
** command.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Mar 13 15:14:25 2015 Nicolas Charvoz
** Last update Fri Mar 27 13:24:51 2015 Nicolas Charvoz
*/

#include "server.h"

int user_server(t_server *s)
{
  write(s->i, c230, strlen(c230));
  write(s->i, "331\r\n", strlen("331\r\n"));
  return (0);
}

int		ls_server(t_server *s)
{
  char		*buffer;

  if ((system("ls -l > /tmp/ftp_tmp") == -1))
    {
      write(s->i, c202, strlen(c202));
      return (0);
    }
  buffer = read_file("/tmp/ftp_tmp");
  if (buffer)
    {
      printf("%s%s\n LIST %s\n%s%s", KGRN, c150, c200, c226, RESET);
      write(s->i, buffer, strlen(buffer));
    }
  free(buffer);
  return (0);
}

int cd_server(t_server *s)
{
  char		final[4096];

  my_cd(s->args[1], s);
  bzero(final, 4096);
  if ((my_cd(s->args[1], s)) == 0)
    {
      sprintf(final, "%s%s%s\n", KGRN,
	      "Successfully changed directory\n", RESET);
      write(s->i, final, strlen(final));
    }
  else
    {
      sprintf(final, "%s%s%s\n", KGRN, "Cannot change directory\n", RESET);
      write(s->i, final, strlen(final));
    }
  return (0);
}

int get_server(t_server *s)
{
  write(s->i, "RETR RECEIVED\n", strlen("RETR RECEIVED\n"));
  return (0);
}
