/*
** graphics.c for graphics in /home/garcia_t/rendu/PSU_2014_lemipc
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Tue Mar  3 10:41:58 2015 antoine garcia
** Last update Sun Mar  8 18:54:28 2015 antoine garcia
*/

#include <unistd.h>
#include <signal.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "lemipc.h"

#define SHEET_WIDTH 50
#define SHEET_HEIGHT 50

char	g_live = 1;

void	loop_sdl(t_lemipc *lemipc, SDL_Rect clip[4], SDL_Surface *faces)
{
  signal(SIGINT, catch);
  while (g_live)
    {
      SDL_FillRect(g_screen, NULL, SDL_MapRGB(g_screen->format, 17, 206, 112));
      display_map(lemipc, clip, faces);
      SDL_Flip(g_screen);
      wait_quit_sdl(&g_live);
      usleep(1000);
    }
}
void	wait_quit_sdl(char *run)
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT)
    *run = 0;
}

void	get_sprites(SDL_Rect clip[4])
{
  clip[ 0 ].x = 0;
  clip[ 0 ].y = 0;
  clip[ 0 ].w = SHEET_WIDTH/2;
  clip[ 0 ].h = SHEET_HEIGHT/2;
  clip[ 1 ].x = SHEET_WIDTH/2;
  clip[ 1 ].y = 0;
  clip[ 1 ].w = SHEET_WIDTH/2;
  clip[ 1 ].h = SHEET_HEIGHT/2;
  clip[ 2 ].x = 0;
  clip[ 2 ].y = SHEET_HEIGHT/2;
  clip[ 2 ].w = SHEET_WIDTH/2;
  clip[ 2 ].h = SHEET_HEIGHT/2;
  clip[ 3 ].x = SHEET_WIDTH/2;
  clip[ 3 ].y = SHEET_HEIGHT/2;
  clip[ 3 ].w = SHEET_WIDTH/2;
  clip[ 3 ].h = SHEET_HEIGHT/2;
}

void	apply(SDL_Rect *clip, SDL_Surface *faces, t_pos *pos)
{
  SDL_Rect	offset;

  offset.x = pos->x * 25;
  offset.y = pos->y * 25;
  SDL_BlitSurface(faces, clip, g_screen, &offset);
}

int	display_map(t_lemipc *lemipc, SDL_Rect clip[4], SDL_Surface *faces)
{
  int	x;
  int	y;
  int	team;
  t_pos	pos;

  get_sprites(clip);
  y = 0;
  while (y < MAX)
    {
      x = 0;
      while (x < MAX)
	{
	  team = lemipc->game->map[y][x];
	  pos.x = x;
	  pos.y = y;
	  if (team != 0)
	    apply(&clip[team - 1], faces, &pos);
	  x++;
	}
      y++;
    }
  return (0);
}
