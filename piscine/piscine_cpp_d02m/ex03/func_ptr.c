/*
** func_ptr.c for  in /home/nicolascharvoz/rendu/piscine_cpp_d02m/ex03
**
** Made by NicolasCharvoz
** Login   <nicolascharvoz@epitech.net>
**
** Started on  Thu Jan  8 10:20:17 2015 NicolasCharvoz
** Last update Thu Jan  8 11:35:11 2015 NicolasCharvoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func_ptr.h"

void print_normal(char *str)
{
  printf("%s\n", str);
}

void print_reverse(char *str)
{
  int i;

  i = strlen(str) - 1;
  while (i > 0)
    {
      printf("%c", str[i]);
      i--;
    }
  printf("%c\n", str[i]);
}

void print_upper(char *str)
{
  int i;
  char *tmp;

  i = 0;
  tmp = malloc((strlen(str) + 1) * sizeof(char));
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  while (str[i] >= 'a' && str[i] <= 'z')
	    {
	      tmp[i] = str[i] - 32;
	      i++;
	    }
	}
      tmp[i] = str[i];
      i++;
    }
  printf("%s\n", tmp);
}

void print_42(char *str)
{
  (void)str;

  printf("42\n");

}

void (*functionList[4])(char*) = {print_normal, print_reverse, print_upper, print_42};

void do_action(t_action action, char *str)
{
 functionList[action](str);
}
