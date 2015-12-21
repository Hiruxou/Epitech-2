/*
** list.c for list in /home/antgar/rendu/PSU_2014_myirc/server_irc
**
** Made by Antoine Garcia
** Login   <antgar@epitech.net>
**
** Started on  Sun Apr  5 14:07:05 2015 Antoine Garcia
** Last update Mon Apr 13 16:45:06 2015 Nicolas Charvoz
*/

#include "server.h"

t_client	*push_back(t_client **client)
{
  t_client	*tmp;
  t_client	*new;

  if (*client == NULL)
    {
      *client = (t_client*)xmalloc(sizeof(t_client));
      (*client)->next = NULL;
      return (*client);
    }
  else
    {
      tmp = *client;
      new = xmalloc(sizeof(t_client));
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
      new->next = NULL;
      return (new);
    }
}
