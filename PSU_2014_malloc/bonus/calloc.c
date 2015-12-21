/*
** calloc.c for calloc in /home/garcia_t/rendu/PSU_2014_malloc/bonus
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Tue Feb 10 14:30:17 2015 antoine garcia
** Last update Sat Feb 14 15:52:04 2015 Nicolas Charvoz
*/

#include <string.h>
#include "malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  void	*new;

  if ((int)nmemb <= 0 || (int)size <= 0)
    return (NULL);
  new = malloc(nmemb * size);
  if (new == NULL)
    return (NULL);
  memset(new, 0, nmemb * size);
  return (new);
}
