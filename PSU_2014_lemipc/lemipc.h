/*
** lemipc.h for lemipc in /home/garcia_t/rendu/PSU_2014_lemipc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Mar  2 11:13:47 2015 antoine garcia
** Last update Sun Mar  8 19:00:34 2015 antoine garcia
*/

#ifndef _LEMIPC_H
# define _LEMIPC_H_

# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <SDL/SDL.h>
# define MAX 30

extern SDL_Surface *g_screen;
extern char g_live;

union semun {
  int              val;
  struct semid_ds *buf;
  unsigned short  *array;
  struct seminfo  *__buf;
};

typedef struct s_pos
{
  int	x;
  int	y;
}		t_pos;

typedef struct s_msg
{
  long	mtype;
  char	str[32];
}		t_msg;

typedef struct s_shared
{
  int	map[MAX][MAX];
  int	msg_id;
  int	sem_id;
}		t_shared;

typedef struct s_player
{
  t_pos	pos;
  int	team;
}		t_player;

typedef struct	s_lemipc
{
  t_player	player;
  key_t		key;
  int		shmid;
  t_shared	*game;
}		t_lemipc;

void		wait_quit_sdl(char*);
int		display_map(t_lemipc*, SDL_Rect clip[4], SDL_Surface*);
void		unlock_sem(int);
void		lock_sem(int);
int		check_death(t_lemipc*);
int		move_random(t_lemipc*);
void		catch(int);
void		init_lemipc(t_lemipc*);
int		launch_game(t_lemipc*);
int		free_ipcs(t_lemipc*);
void		loop_sdl(t_lemipc *, SDL_Rect clip[4], SDL_Surface *);
#endif
