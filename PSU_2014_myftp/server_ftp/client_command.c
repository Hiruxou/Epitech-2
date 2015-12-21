/*
** client_command.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 17 11:39:45 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:49:40 2015 Nicolas Charvoz
*/

#include "server.h"

int lls_server(t_server *s)
{
  size_t	size;
  char		*final;

  size = strlen(KGRN) + strlen(c200) + strlen(RESET) + 1;
  final = xmalloc(size * sizeof(char));
  memset(final, 0, size);
  sprintf(final, "%s%s%s", KGRN, c200, RESET);
  write(s->i, final, strlen(final));
  return (0);
}

int lcd_server(t_server *s)
{
  write(s->i, c202, strlen(c202));
  return (0);
}

int lpwd_server(t_server *s)
{
  write(s->i, c200, strlen(c200));
  return (0);
}

int clear_client(t_server *s)
{
  write(s->i, c200, strlen(c200));
  return (0);
}

int noopuser_client(t_server *s)
{
  write(s->i, c530, strlen(c530));
  return (0);
}
