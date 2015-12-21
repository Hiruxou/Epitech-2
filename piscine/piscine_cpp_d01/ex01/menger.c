/*
** menger.c for  in /home/charvo_a/rendu/piscine_cpp_d01/ex01
**
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Jan  7 19:12:17 2015 Charvoz Nicolas
** Last update Thu Jan  8 08:59:24 2015 NicolasCharvoz
*/

#include <stdio.h>

void	printSize(int nbr)
{
  if (nbr >= 0 && nbr <= 9)
    printf("00%d", nbr);
  else if (nbr >= 10 && nbr <= 99)
    printf("0%d", nbr);
  else
    printf("%d", nbr);
}

void	run(int size, int level, int x, int y)
{
  int	sub;

  sub = 0;
  if (!(size % 3) && level > 0 && level < size)
    {
      sub = size / 3;
      printSize(sub);
      printf(" ");
      printSize(sub + x);
      printf(" ");
      printSize(sub + y);
      printf("\n");
      level--;
      run(sub, level, x, y);
      run(sub, level, x, y + sub);
      run(sub, level, x, y + 2 * sub);
      run(sub, level, x + sub, y);
      run(sub, level, x + sub, y + 2 * sub);
      run(sub, level, x + 2 * sub, y);
      run(sub, level, x + 2 * sub, y + sub);
      run(sub, level, x + 2 * sub, y + 2 * sub);
    }
}

void	menger(int size, int level)
{
  if (level < size)
    run(size, level, 0, 0);
}
