/*
** ressources_init.c for  in /home/nicolaschr/rendu/PSU_2014_philo
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Feb 23 13:34:50 2015 Nicolas Charvoz
** Last update Thu Feb 26 09:13:30 2015 Audibert Louis
*/

#include "philosophe.h"

void init_colors()
{
  g_philo[0].color = "33";
  g_philo[1].color = "31";
  g_philo[2].color = "34";
  g_philo[3].color = "35";
  g_philo[4].color = "36";
  g_philo[5].color = "32";
  g_philo[6].color = "30";
}

void ressources_init()
{
  int i;

  i = 0;
  init_colors();
  while (i < 7)
    {
      g_philo[i].state = 'R';
      g_philo[i].think_time = rand() % 5;
      g_philo[i].eat_time = rand() % 5;
      g_philo[i].rest_time = rand() % 5;
      g_philo[i].hunger = 10 + rand() % 50;
      g_philo[i].rice = 100;
      g_philo[i].i = i;
      g_philo[i].st_i = 0;
      g_chopsticks[i] = 0;
      pthread_create(&(g_philo[i].handler), NULL, set_action, &g_philo[i]);
      i++;
    }
}

void state_print()
{
  int i;

  fprintf(stdout, "\n\nResult : \n\n");
  i = 0;
  while (i < 7)
    {
      g_philo[i].states[g_philo[i].st_i] = 0;
      printf("\e[1;%smPhilosophe %d : [%s]\e[m\n",
	     g_philo[i].color, i, g_philo[i].states);
      ++i;
    }
}

void wait_action()
{
  int i ;

  i = 0;
  while (i < 7)
    {
      pthread_join((g_philo[i].handler), NULL);
      i++;
    }
}
