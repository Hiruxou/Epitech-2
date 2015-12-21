/*
** realloc.c for realloc in /home/garcia_t/rendu/malloc
** 
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri Feb  6 11:10:13 2015 antoine garcia
** Last update Fri Feb  6 11:47:17 2015 antoine garcia
*/

#include <string.h>
#include "malloc.h"

void	*realloc(void *ptr, size_t size)
{

  t_block	*block;
  void		*new;
  
  if (ptr == NULL)
    return (malloc(size));
  if (addr_is_valid(ptr) == 1)
    {
      block = get_block(ptr);
      new = malloc(size);
      if (!new)
	return (NULL);
      memcpy(new, ptr, block->size);
      free(ptr);
      return (new);
    }
}
