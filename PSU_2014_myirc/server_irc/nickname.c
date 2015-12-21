/*
** nickname.c for  in /home/nicolaschr/rendu/PSU_2014_myirc/server_irc
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Apr 13 23:01:32 2015 Nicolas Charvoz
** Last update Mon Apr 13 23:01:39 2015 Nicolas Charvoz
*/

#include "server.h"

void	change_nickname(t_server *s, t_client *c, char *str)
{
  t_client	*list;
  char		buffer[4096];

  list = s->clients;
  if (list->chan[0] != '\0')
    {
      while (list)
	{
	  if (!strcmp(list->chan, c->chan) && (list != c))
	    {
	      snprintf(buffer, 4096,
		       "%s change is nickname to %s\n", c->name, str);
	      send(list->c_fd, buffer, strlen(buffer), 0);
	      snprintf(c->name, 4096, "%s", str);
	    }
	  list = list->next;
	}
    }
  snprintf(c->name, 4096, "%s", str);
}
