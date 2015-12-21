/*
** philosophe.h for philosophes in /home/nicolaschr/rendu/PSU_2014_philo
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Feb 23 13:33:02 2015 Nicolas Charvoz
** Last update Thu Feb 26 09:10:00 2015 Audibert Louis
*/

#ifndef _PHILOSOPHE_H_
# define _PHILOSOPHE_H_

# include <pthread.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_philosophe {

  int		i;
  pthread_t	handler;
  char		state;
  int		think_time;
  int		eat_time;
  int		rest_time;
  char		*name;
  int		rice;
  int		hunger;
  char		*color;
  char		states[32];
  int		st_i;

}		t_philosophe;

extern int		g_chopsticks[7];
extern t_philosophe	g_philo[7];
extern pthread_mutex_t	g_choose;

void ressources_init();
void wait_action();
void *set_action(void *);
void time_to_relax(t_philosophe *p);
void time_to_think(t_philosophe *p);
void time_to_eat(t_philosophe *p);
void init_colors();
void state_print();

#endif
