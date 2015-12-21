/*
** command.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Mar 12 15:40:47 2015 Nicolas Charvoz
** Last update Sun Mar 29 17:46:00 2015 Nicolas Charvoz
*/

#include "client.h"

int user_ftp(t_client *c)
{
  if (c->args[1] == NULL)
    {
      printf("Please enter a login\n");
      write(c->sd, "NOOPUSER\n", strlen("NOOPUSER\n"));
      return (0);
    }
  if (c->username != NULL)
      memset(c->username, 0, strlen(c->username));
  c->username = strdup(c->args[1]);
  printf("Thanks for login in %s\n", c->username);
  write(c->sd, "USER\n", strlen("USER\n"));
  return (0);
}

int ls_ftp(t_client *c)
{
  if (c->username != NULL)
    write(c->sd, "LIST\n", strlen("LIST\n"));
  else
    {
      printf("%s\n", c530);
      write(c->sd, "NOOPUSER\n", strlen("NOOPUSER\n"));
    }
  return (0);
}

int cd_ftp(t_client *c)
{
  char final[80];

  sprintf(final, "CWD %s\n", c->args[1]);
  if (c->username != NULL)
    write(c->sd, final, strlen(final));
  else
    {
      printf("%s\n", c530);
      write(c->sd, "NOOPUSER\n", strlen("NOOPUSER\n"));
    }
  return (0);
}

int pwd_ftp(t_client *c)
{
  if (c->username != NULL)
    write(c->sd, "PWD\n", strlen("PWD\n"));
  else
    {
      printf("%s\n", c530);
      write(c->sd, "NOOPUSER\n", strlen("NOOPUSER\n"));
    }
  return (0);
}
