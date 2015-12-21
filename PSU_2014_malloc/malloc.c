/*
** malloc.c for malloc in /home/garcia_t/rendu/malloc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Thu Feb  5 12:14:01 2015 antoine garcia
** Last update Sat Feb 14 15:48:21 2015 Nicolas Charvoz
*/

#include <pthread.h>
#include "malloc.h"

void	*g_base = NULL;
static pthread_mutex_t mutex_stock = PTHREAD_MUTEX_INITIALIZER;

static  t_block *first_malloc_call(size_t size)
{
  t_block	*block;

  block = extend_memory(NULL, size);
  g_base = block;
  return (block);
}

static t_block	*use_free_block(size_t size, t_block *last)
{
  t_block	*block;

  last = g_base;
  block = find_block(&last, size);
  if (block)
    {
      if (block->size - size >= (SIZE + sizeof(int)))
	split_memory(block, size);
      block->free = 0;
    }
  else
    block = extend_memory(last, size);
  return (block);
}

void		*malloc(size_t size)
{
  t_block	*block;
  t_block	*last;
  size_t	align_size;

  if ((int) size <= 0)
    return (NULL);
  align_size = align(size);
  pthread_mutex_lock(&mutex_stock);
  if (g_base)
    {
      block = use_free_block(align_size, last);
      if (block == NULL)
	return (NULL);
    }
  else
    {
      block = first_malloc_call(align_size);
      if (block == NULL)
	return (NULL);
    }
  pthread_mutex_unlock(&mutex_stock);
  return (block->data);
}
