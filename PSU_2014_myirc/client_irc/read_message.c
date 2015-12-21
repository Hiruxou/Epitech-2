/*
** read_message.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/client_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Apr  7 15:55:32 2015 Nicolas Charvoz
** Last update Mon Apr 13 13:15:21 2015 Nicolas Charvoz
*/

#include "client.h"

void send_message(t_client *c)
{
  bzero(c->buf, 4096);
  c->rc = read(0, c->buf, 4095);
  if (c->buf[0] != '\n' && c->rc != 0 && c->buf[0] != EOF)
    {
      if (c->buf[0] == '/')
	{
	  parser(c->buf, c);
	  exec_cmd(c, 1);
	}
      else
	{
	  exec_cmd(c, 0);
	}
    }
}
