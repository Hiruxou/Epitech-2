/*
** align.c for align in /home/garcia_t/rendu/malloc
** 
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
** 
** Started on  Fri Feb  6 11:43:39 2015 antoine garcia
** Last update Fri Feb  6 11:45:39 2015 antoine garcia
*/

#include "malloc.h"

size_t	align(size_t size)
{
  return ((((size - 1) / 4) * 4) + 4);
}
