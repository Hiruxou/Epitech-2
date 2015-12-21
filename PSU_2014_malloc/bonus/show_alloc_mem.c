/*
** show_alloc_mem.c for show_alloc_meme in /home/garcia_t/rendu/PSU_2014_malloc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Feb  9 14:04:28 2015 antoine garcia
** Last update Sat Feb 14 15:54:08 2015 Nicolas Charvoz
*/

#include <stdio.h>
#include "malloc.h"

void		show_alloc_mem()
{
  t_block	*block;

  block = g_base;
  printf("break : %p\n", sbrk(0));
  if (block == NULL)
    printf("No memory\n");
  else
    {
      while (block)
	{
	  if (block->free == 0)
	    printf("%p - %p : %zu octets\n", &block->data,
		   &block->data + block->size, block->size);
	  block = block->next;
	}
    }
}
