/*
** init_struct.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 20:21:50 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:48:32 2015 Nicolas Charvoz
*/

#include "client.h"

void	init_struct(t_client *c)
{
  c->length = sizeof(int);
  c->totalcnt = 0;
  c->data = xmalloc(100 * sizeof(char));
  bzero(&(c->data), 0);
  c->data = "This is a test string from client";
  c->username = NULL;
}
