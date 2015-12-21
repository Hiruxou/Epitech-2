/*
** exec.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 10 18:23:07 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:56:20 2015 Nicolas Charvoz
*/

#include "server.h"

void	init_cmd(int(**serv)(t_server *s))
{
  int	i;

  i = 0;
  serv[i++] = &user_server;
  serv[i++] = &ls_server;
  serv[i++] = &lls_server;
  serv[i++] = &cd_server;
  serv[i++] = &lcd_server;
  serv[i++] = &get_server;
  serv[i++] = &put_server;
  serv[i++] = &pwd_server;
  serv[i++] = &lpwd_server;
  serv[i++] = &quit_server;
  serv[i++] = &clear_client;
  serv[i++] = &noopuser_client;
  serv[i++] = &noop_server;
}

char	**init_tram()
{
  char	**tab;
  int	i;

  tab = xmalloc(SIZE_OF_TAB * sizeof(char*));
  i = 0;
  tab[i++] = "USER";
  tab[i++] = "LIST";
  tab[i++] = "LLS";
  tab[i++] = "CWD";
  tab[i++] = "LCWD";
  tab[i++] = "RETR";
  tab[i++] = "STOR";
  tab[i++] = "PWD";
  tab[i++] = "LPWD";
  tab[i++] = "QUIT";
  tab[i++] = "CLEAR";
  tab[i++] = "NOOPUSER";
  tab[i++] = "NOOP";
  tab[i++] = NULL;
  return (tab);
}

int	check_cmd(t_server *server)
{
  int (*serv[14])(t_server *s);
  int i;
  char **tab;

  i = 0;
  init_cmd(serv);
  tab = init_tram();
  while (tab[i])
    {
      if (strcmp(tab[i], server->args[0]) == 0)
        {
          serv[i](server);
          return (0);
        }
      i++;
    }
  return (0);
}

void    exec_cmd(t_server *s)
{
  parser(s, s->buf);
  check_cmd(s);
}
