//
// Game.hh for Game in /home/garcia_t/rendu/cpp_nibbler
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Tue Mar 24 14:59:12 2015 antoine garcia
// Last update Fri Apr  3 06:58:16 2015 Antoine Garcia
//

#ifndef _GAME_HH_
# define _GAME_HH_

#include <sys/time.h>
#include "struct.h"
#include <list>
#include "IDisplayModule.hh"

class  Game
{
  int	_width;
  int	_height;
  IDisplayModule	*_plug;
  int	_countEat;
  t_dir	_dir;
  std::list<Coord>_snake;
  std::list<Apple>_appleList;
  bool	_eat;
  int	 _score;
  struct timeval _appleTime;
  void	bonus_or_malus();
public:
  Game(int width, int height, IDisplayModule *);
  void run();
  void	createApple();
  int	gameOver();
  void	setDirection(t_key key);
  void	move();
  void	hasEat();
};

#endif
