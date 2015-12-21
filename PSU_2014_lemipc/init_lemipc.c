/*
** init_lemipc.c for lemipc in /home/garcia_t/rendu/PSU_2014_lemipc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Mon Mar  2 13:07:16 2015 antoine garcia
** Last update Sun Mar  8 19:00:39 2015 antoine garcia
*/

#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "lemipc.h"

SDL_Surface *g_screen;

static void	start_SDL(t_lemipc *lemipc)
{
  SDL_Rect	clip[4];
  SDL_Surface	*faces;

  SDL_Init(SDL_INIT_VIDEO);
  g_screen = SDL_SetVideoMode(25 * MAX, 25 * MAX, 32, SDL_HWSURFACE);
  faces = IMG_Load("./faces_resize.png");
  SDL_WM_SetCaption("Lemipc by charvo_a & garcia_t", NULL);
  loop_sdl(lemipc, clip, faces);
  SDL_Quit();
}

void	launch_graphics(t_lemipc *lemipc)
{
  int	pid;

  pid = fork();
  if (pid == 0)
    {
      start_SDL(lemipc);
      exit (0);
    }
}

static void	create_game_board(t_lemipc *lemipc)
{
  int	i;

  i = 0;
  while (i < MAX)
    {
      memset(lemipc->game->map[i], 0, MAX);
      i++;
    }
  launch_graphics(lemipc);
}

static void create_shared_memory(t_lemipc *lemipc)
{
  union	semun	semun;

  semun.val = 1;
  lemipc->shmid = shmget(lemipc->key, sizeof(*lemipc->game), IPC_CREAT
			 | SHM_R | SHM_W);
  lemipc->game = (t_shared *)shmat(lemipc->shmid, NULL, 0);
  create_game_board(lemipc);
  lemipc->game->sem_id = semget(lemipc->key, 1, IPC_CREAT | SHM_R | SHM_W);
  lemipc->game->msg_id = msgget(lemipc->key, IPC_CREAT | SHM_R | SHM_W);
  semctl(lemipc->game->sem_id, 0, SETVAL, semun);
}

void	init_lemipc(t_lemipc *lemipc)
{
  char	*pathname;

  srand(time(NULL));
  pathname = malloc(4096 * sizeof(char));
  pathname = getcwd(pathname, 4096);
  lemipc->key = ftok(pathname, 0);
  lemipc->shmid = shmget(lemipc->key, sizeof(*lemipc->game), SHM_R | SHM_W);
  if (lemipc->shmid == -1)
    {
      printf("Shared Memory Created\n");
      create_shared_memory(lemipc);
    }
  else
    {
      printf("Already Exist\n");
      lemipc->game = (t_shared *)shmat(lemipc->shmid, NULL, 0);
    }
}
