/*
** ptr_tricks.c for $ in /home/charvo_a
** 
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
** 
** Started on  Thu Jan  8 13:41:25 2015 Charvoz Nicolas
** Last update Thu Jan  8 13:41:57 2015 Charvoz Nicolas
*/

#include "ptr_tricks.h"

int get_array_nb_elem(int *ptr1, int *ptr2) 
{
  return (ptr2 - ptr1);
}

t_whatever *get_struct_ptr(int *member_ptr) 
{
  t_whatever base;
  
  return (void*)member_ptr - ((void*)&base.member - (void*)&base);
}
