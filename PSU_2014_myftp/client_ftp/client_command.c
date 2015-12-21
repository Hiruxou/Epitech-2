/*
** client_command.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 17 11:49:10 2015 Nicolas Charvoz
** Last update Sun Mar 29 17:45:47 2015 Nicolas Charvoz
*/

#include "client.h"

int lls_ftp(t_client *c)
{
  system("ls -l");
  write(c->sd, "LLS\n", strlen("LLS\n"));
  return (0);
}

int lcd_ftp(t_client *c)
{
  write(c->sd, "LCWD\n", strlen("LCWD\n"));
  return (0);
}

int lpwd_ftp(t_client *c)
{
  system("pwd");
  write(c->sd, "LPWD\n", strlen("LPWD\n"));
  return (0);
}
