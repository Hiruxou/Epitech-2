/*
** generic_list.c for  in /home/nicolaschr/rendu/piscine_cpp_d02a/ex02
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Fri Jan  9 09:29:36 2015 Nicolas Charvoz
** Last update Fri Jan  9 09:29:40 2015 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "generic_list.h"


unsigned int	list_get_size(t_list list)
{
  if (list == NULL)
    return (0);
  return (list_get_size(list->next) + 1);
}

t_bool		list_is_empty(t_list list)
{
  if (list == NULL)
    return (TRUE);
  return (FALSE);
}

void		list_dump(t_list list, t_value_displayer val_disp)
{
  while (list != NULL)
    {
      (*val_disp)(list->value);
      list = list->next;
    }
}

t_bool		list_add_elem_at_front(t_list *front_ptr, void *elem)
{
  t_node *node;

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (FALSE);
  node->value = elem;
  node->next = *front_ptr;
  *front_ptr = node;
  return (TRUE);
}

t_bool		list_add_elem_at_back(t_list *front_ptr, void *elem)
{
  t_node *node;
  t_list tmp;

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (FALSE);
  node->value = elem;
  node->next = NULL;
  if (*front_ptr == NULL)
    *front_ptr = node;
  else
    {
      tmp = *front_ptr;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = node;
    }
  return (TRUE);
}

t_bool		list_add_elem_at_position(t_list *front_ptr, void *elem, unsigned int position)
{
  t_list list;
  t_node *node;

  if (position == 0)
    return (list_add_elem_at_front(front_ptr, elem));
  if (*front_ptr == NULL)
    return (FALSE);
  list = *front_ptr;
  while (--position)
    {
      list = list->next;
      if (list == NULL)
	return (FALSE);
    }
  node = malloc(sizeof(*node));
  node->value = elem;
  node->next = NULL;
  if (node == NULL)
    return (FALSE);
  node->next = list->next;
  list->next = node;
  return (TRUE);
}

t_bool		list_del_elem_at_front(t_list* front_ptr)
{
  t_list list;

  list = *front_ptr;
  if (list == NULL)
    return (FALSE);
  *front_ptr = list->next;
  free(list);
  return (TRUE);
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list list;
  t_list previous;

  list = *front_ptr;
  previous = NULL;
  if (list == NULL)
    return (FALSE);
  while (list->next)
    {
      previous = list;
      list = list->next;
    }
  if (previous)
      previous->next = NULL;
  else
    *front_ptr = NULL;
  free(list);
  return (TRUE);
}

t_bool		list_del_elem_at_position(t_list* front_ptr, unsigned int position)
{
  t_list list;
  t_list previous;

  if (position == 0)
    {
      printf("front\n");
      return list_del_elem_at_front(front_ptr);
    }
  if (*front_ptr == NULL)
    return (FALSE);
  previous = *front_ptr;
  list = previous->next;
  while (--position)
    {
      if (list == NULL)
	return (FALSE);
      previous = list;
      list = list->next;
    }
  if (list)
    previous->next = list->next;
  free(list);
  return (TRUE);
}

void		list_clear(t_list *front_ptr)
{
  t_list list;
  t_list prev;

  list = *front_ptr;
  if (list != NULL)
    {
      prev = list;
      list = list->next;
      free(prev);
    }
  *front_ptr = NULL;
}

double		list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return (0);
  return (list->value);
}

double		list_get_elem_at_back(t_list list)
{
  if (list == NULL)
    return (0);
  while (list->next)
    list = list->next;
  return (list->value);
}

double		list_get_elem_at_position(t_list list, unsigned int position)
{
  if (list == NULL)
    return (0);
  while (position--)
    {
      list = list->next;
      if (list == NULL)
	return (0);
    }
  return (list->value);
}

t_node		*list_get_first_node_with_value(t_list list, void *value, t_value_comparator val_comp)
{
  while (list)
    {
      if ((*val_comp)(list->value, value))
	return (list);
      list = list->next;
    }
  return (NULL);
}
