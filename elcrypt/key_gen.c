/*
** key_gen.c for  in /home/nicolaschr/rendu/elcrypt
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sun Mar 15 12:04:37 2015 Nicolas Charvoz
** Last update Sun Mar 15 12:04:59 2015 Nicolas Charvoz
*/

#include "elcrypt.h"

static void	rotate(char *array, int begin, int end)
{
  char	temp;

  while (begin < end)
    {
      temp = array[begin];
      array[begin] = array[end];
      array[end] = temp;
      begin++;
      end--;
    }
}

void	leftRotate(char *test, int number)
{
  rotate(test, 0, number - 1);
  rotate(test, number, strlen(test) - 1);
  rotate(test, 0, strlen(test) - 1);
}
