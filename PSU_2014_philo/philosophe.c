/*
** philosophe.c for  in /home/nicolaschr/rendu/PSU_2014_philo
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Feb 23 13:32:49 2015 Nicolas Charvoz
** Last update Sat Feb 28 14:35:44 2015 Audibert Louis
*/

#include "philosophe.h"

int g_chopsticks[7];
t_philosophe g_philo[7];
pthread_mutex_t g_choose = PTHREAD_MUTEX_INITIALIZER;

void time_to_eat(t_philosophe *p)
{
  p->state = 'E';
  p->states[p->st_i] = p->state;
  p->st_i++;
  g_chopsticks[p->i] = 1;
  g_chopsticks[(p->i + 1) % 7] = 1;
  pthread_mutex_unlock(&g_choose);
  fprintf(stdout, "\e[1;%smPhilosophe %d : Je suis en train de manger !\e[m\n",
	  p->color, p->i);
  sleep(p->eat_time);
  p->rice -= p->hunger;
  if (p->rice < 0)
    p->rice = 0;
  fprintf(stdout,
	  "\e[1;%smPhilosophe %d : J'ai fini de manger\
 %d grains de riz (Il me reste: %d grains)!\e[m\n",
	  p->color, p->i, p->hunger, p->rice);
  pthread_mutex_lock(&g_choose);
  g_chopsticks[p->i] = 0;
  g_chopsticks[(p->i + 1) % 7] = 0;
  pthread_mutex_unlock(&g_choose);
}

void time_to_think(t_philosophe *p)
{
  p->state = 'T';
  p->states[p->st_i] = p->state;
  p->st_i++;
  g_chopsticks[p->i] = 1;
  pthread_mutex_unlock(&g_choose);
  fprintf(stdout, "\e[1;%smPhilosophe %d : Je suis en train de penser !\e[m\n",
	  p->color, p->i);
  sleep(p->think_time);
  fprintf(stdout, "\e[1;%smPhilosophe %d : J'ai fini de penser !\e[m\n",
	  p->color, p->i);
  while (p->state != 'E')
    {
      pthread_mutex_lock(&g_choose);
      if (g_chopsticks[(p->i + 1) % 7] == 0)
	time_to_eat(p);
      else
	pthread_mutex_unlock(&g_choose);
    }
}

void time_to_relax(t_philosophe *p)
{
  pthread_mutex_unlock(&g_choose);
  if (p->state == 'R')
    return ;
  p->state = 'R';
  p->states[p->i] = p->state;
  p->st_i++;
  fprintf(stdout, "\e[1;%smPhilosophe %d : Je vais faire une sieste !\e[m\n",
	  p->color, p->i);
  sleep(p->rest_time);
  fprintf(stdout, "\e[1;%smPhilosophe %d : J'ai fini ma sieste !\e[m\n",
	  p->color, p->i);
}

void *set_action(void *args)
{
  t_philosophe *p;
  int left;
  int right;

  p = (t_philosophe*)args;
  fprintf(stdout,
	  "\e[1;%smPhilosophe %d : S'est joint à la table!\e[m\n",
	  p->color, p->i);
  while (p->rice > 0)
    {
      pthread_mutex_lock(&g_choose);
      left = g_chopsticks[p->i];
      right = g_chopsticks[(p->i + 1) % 7];
      if (left == 0 && right == 0 && p->state != 'E')
	time_to_eat(p);
      else if (left == 0 && p->state != 'T' && p->state != 'E')
	time_to_think(p);
      else
	time_to_relax(p);
    }
  fprintf(stdout, "\e[1;%smPhilosophe %d : A quitté la table! \e[m\n",
	  p->color, p->i);

  return (NULL);
}
