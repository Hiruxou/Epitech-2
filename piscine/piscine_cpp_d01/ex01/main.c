/*
** main.c for  in /home/charvo_a/rendu/piscine_cpp_d01/ex01
**
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Jan  7 19:16:13 2015 Charvoz Nicolas
** Last update Thu Jan  8 08:59:12 2015 NicolasCharvoz
*/

#include <stdio.h>
#include <ctype.h>

void	menger(int size, int level);

int	my_getnbr(char *str)
{
  int	num;
  int	i;

  num = 0;
  i = 0;
  while (isdigit(str[i]))
    {
      num = num * 10 + str[i] - 48;
      i++;
    }
  return (num);
}

int	main(int argc, char **argv)
{
  if (argc == 3)
    menger(my_getnbr(argv[1]), my_getnbr(argv[2]));
  return (0);
}
