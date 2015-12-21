/*
** block.c for block in /home/garcia_t/rendu/malloc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Thu Feb  5 12:05:51 2015 antoine garcia
** Last update Sat Feb 14 15:51:56 2015 Nicolas Charvoz
*/

#include "malloc.h"

t_block		*find_block(t_block **last, size_t size)
{
  t_block	*block;

  block  = g_base;
  while (block && !(block->free && block->size >= size))
    {
      *last = block;
      block = block->next;
    }
  return (block);
}

t_block		*extend_memory(t_block *last, size_t size)
{
  t_block	*block;

  block = sbrk(0);
  if (sbrk(SIZE + size) == (void*) -1)
    return (NULL);
  block->size = size;
  block->prev = last;
  block->next = NULL;
  block->free = 0;
  block->ptr = block->data;
  if(last)
    last->next = block;
  return (block);
}

void		split_memory(t_block *b, size_t s)
{
  t_block	*new;

  new = (t_block*)(b->data + s);
  new->size = b->size - s - SIZE;
  new->next = b->next;
  new->prev = b;
  new->free = 1;
  new->ptr = new->data;
  b->size = s;
  b->next = new;
  if (new->next)
    new->next->prev = new;
}
