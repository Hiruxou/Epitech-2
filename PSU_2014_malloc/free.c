/*
** free.c for free in /home/garcia_t/rendu/malloc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Thu Feb  5 14:42:38 2015 antoine garcia
** Last update Sat Feb 14 15:47:48 2015 Nicolas Charvoz
*/

#include "malloc.h"

t_block		*get_block(void *ptr)
{
  char		*tmp;
  t_block	block;

  tmp = ptr;
  tmp -= (SIZE - 1);
  ptr = tmp;
  return (ptr);
}

int	addr_is_valid(void *ptr)
{
  if (g_base)
    {
      if (ptr > g_base && ptr < sbrk(0))
	return (1);
    }
  return (0);
}

void		free(void *ptr)
{
  t_block	*block;

  if (addr_is_valid(ptr) == 1)
    {
      block = get_block(ptr);
      block->free = 1;
    }
}
