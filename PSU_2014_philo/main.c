/*
** main.c for  in /home/nicolaschr/rendu/PSU_2014_philo
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  2 21:08:59 2015 Nicolas Charvoz
** Last update Mon Mar  2 21:09:01 2015 Nicolas Charvoz
*/

#include "philosophe.h"

int		main()
{
  srand(time(NULL));
  ressources_init();
  wait_action();
  return (0);
}
