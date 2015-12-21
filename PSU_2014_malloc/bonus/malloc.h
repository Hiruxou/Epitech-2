/*
** malloc.h for malloc in /home/garcia_t/rendu/malloc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Thu Feb  5 12:04:39 2015 antoine garcia
** Last update Sat Feb 14 15:53:45 2015 Nicolas Charvoz
*/

#ifndef MALLOC_H_
# define MALLOC_H_
# include <unistd.h>
# include <stdio.h>

extern void *g_base;

typedef struct __attribute__((__packed__))	s_block
{
  size_t					size;
  struct s_block				*prev;
  struct s_block				*next;
  int						free;
  void						*ptr;
  char						data[1];
}						t_block;

#define SIZE sizeof(t_block)

void	*malloc(size_t);
void	free(void*);
void	*realloc(void *ptr, size_t size);
void	*calloc(size_t, size_t);
t_block	*extend_memory(t_block *last, size_t size);
void	split_memory(t_block *, size_t);
t_block	*find_block(t_block **last, size_t size);
int	addr_is_valid(void*);
t_block	*get_block(void *ptr);
void	show_alloc_mem();
size_t	align(size_t);

#endif
