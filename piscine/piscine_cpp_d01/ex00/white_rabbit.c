/*
** white_rabbit.c for ex00 in /home/charvo_a/rendu/piscine_cpp_d01/ex00
**
** Made by Charvoz Nicolas
** Login   <charvo_a@epitech.net>
**
** Started on  Wed Jan  7 09:38:46 2015 Charvoz Nicolas
** Last update Thu Jan  8 09:13:16 2015 NicolasCharvoz
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	follow_the_white_rabbit()
{
  int	dice_result;
  int	sum;

  dice_result = 0;
  sum = 0;

  while (dice_result != 37 && dice_result != 1)
    {
      dice_result = ((random() % 37) + 1);
      if (dice_result == 3)
	{
	  while (dice_result == 3 || ((random() % 37 + 1)))
	    {
	      sum += 3;
	      dice_result = dice_result + ((random() % 37) + 1) + 3;
	    }
	}
      if (dice_result == 13 || dice_result >= 34)
	printf("droite\n");
      else if ((dice_result >= 4 && dice_result <= 6) || dice_result == 17 || dice_result == 28 || (dice_result >= 18 && dice_result <= 21))
	printf("gauche\n");
      else if (dice_result == 15 || dice_result == 10 || dice_result == 23)
	printf("devant\n");
      else if (dice_result == 26 || ((dice_result % 8) == 0))
	printf("derriere\n");
      sum += dice_result;
      if (sum >= 397)
	{
	  dice_result = 1;
	}
    }
  printf ("LAPIN !!!\n");
  return (sum);
}
