//
// Game.cpp for Game in /home/antgar/rendu/cpp_nibbler
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Thu Mar 26 13:17:38 2015 Antoine Garcia
// Last update Sun Apr  5 12:23:05 2015 Nicolas Charvoz
//

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "../Game.hh"
#include <ctime>
#include "../Apple.hpp"

#define INIT_SIZE 4
#define SPEED_INIT 1
#define SPEED_MAX 3
#define TIME 150000

Game::Game(int width, int height, IDisplayModule *plugin):_width(width),_height(height), _plug(plugin), _dir(RIGHT), _eat(false)
{
  int	i;

  i = 0;
  srand(time(NULL));
  while (i < INIT_SIZE)
    {
      _snake.push_back(Coord(height/2, (width/2) - i));
      i++;
    }
  _score = 0;
  _countEat = 0;
}

void	Game::createApple()
{
  Apple	apple;
  bool	is_ok = false;

  std::list<Coord>::iterator it;
  while (!is_ok)
    {
      apple.setCoord(Coord(rand() % _height, rand() % _width));
      if (_countEat == 5)
	{
	  gettimeofday(&_appleTime, NULL);
	  apple.setType(BIG_APPLE);
	  _countEat = 0;
	}
      else
	apple.setType(NORMAL_APPLE);
      it = std::find(_snake.begin(), _snake.end(), apple.getCoord());
      if (it == _snake.end())
	{
	  is_ok = true;
	  _appleList.push_back(apple);
	}
    }
}

void	Game::bonus_or_malus()
{
  int	choose = rand() % 2;

  if (choose == 1)
    _score += 20;
  else
    _score -= 10;
}
void	Game::hasEat()
{
  Coord	head;
  struct timeval checkTime;

  head = _snake.front();
  gettimeofday(&checkTime, NULL);
  for(std::list<Apple>::iterator it = _appleList.begin(); it != _appleList.end(); ++it)
    {
      if (((*it).getType() == BIG_APPLE) && (checkTime.tv_sec - _appleTime.tv_sec) >= 5)
	{
	  it = _appleList.erase(it);
	  this->createApple();
	}
      if (head == (*it).getCoord())
	{
	  _eat = true;
	  if ((*it).getType() == BIG_APPLE)
	    bonus_or_malus();
	  else
	    _score += 10;
	  _countEat += 1;
	  it =  _appleList.erase(it);
	  this->createApple();
	}
    }
}

int	Game::gameOver()
{
  Coord	head;
  std::list <Coord>::iterator it = _snake.begin();

  head = _snake.front();
  if (head._x < 0 || head._y < 0 || head._x >= _width || head._y >= _height)
    return (1);
  if (find(++it, _snake.end(), head) != _snake.end())
    return (1);
  return (0);
}

void	Game::setDirection(t_key key)
{
  if (key == LEFT_KEY && _dir == RIGHT)
    _dir = UP;
  else if (key == LEFT_KEY && _dir == UP)
    _dir = LEFT;
  else if (key == LEFT_KEY && _dir == DOWN)
    _dir = RIGHT;
  else if (key == LEFT_KEY && _dir == LEFT)
    _dir = DOWN;
  else if (key == RIGHT_KEY && _dir == RIGHT)
    _dir = DOWN;
  else if (key == RIGHT_KEY && _dir == DOWN)
    _dir = LEFT;
  else if (key == RIGHT_KEY && _dir == LEFT)
    _dir = UP;
  else
    _dir = RIGHT;
}

void	Game::move()
{
  Coord	tmp;

  tmp = _snake.front();
  if (_eat == true)
    _eat = false;
  else
    _snake.pop_back();
  switch(_dir)
    {
    case UP:
      tmp._y++;
      break;
    case DOWN:
      tmp._y--;
      break;
    case RIGHT:
      tmp._x++;
      break;
    case LEFT:
      tmp._x--;
      break;
    }
  _snake.push_front(tmp);
}

void	timeval_diff(struct timeval *diff,
		 struct timeval *end_time,
		 struct timeval *start_time)
{
  struct timeval temp_diff;
  if (diff == NULL)
    diff = &temp_diff;
  diff->tv_sec = end_time->tv_sec - start_time->tv_sec;
  diff->tv_usec = end_time->tv_usec - start_time->tv_usec;
  while (diff->tv_usec < 0)
    {
      diff->tv_usec+=1000000;
      diff->tv_sec -=1;
    }
}

void	Game::run()
{
  bool	check = true;
  t_key	event;
  struct timeval before, after, interval;
  int	speed = SPEED_INIT;
  bool	check_speed = false;
  int	init_apple = rand() % 10 + 1;
  int	i = 0;

  _plug->init(_width, _height);
  while (i++ < init_apple)
    this->createApple();
  gettimeofday(&before,NULL);
  while (check)
    {
      if (this->gameOver())
	{
	  delete _plug;
	  this->displayGameOver();
	  check = false;
	  break;
	}
      this->hasEat();
      _plug->draw(_snake, _appleList);
      _plug->drawScore(_score);
      event = _plug->getEvent();
      if (event == ESC_KEY)
	{
	  delete _plug;
	  check = false;
	}
      if (event == SPACE_KEY)
	{
	  if (!check_speed)
	    {
	      speed = SPEED_MAX;
	      check_speed = true;
	    }
	  else
	    {
	      speed = SPEED_INIT;
	      check_speed = false;
	    }
	}
      else if (event != NONE)
	this->setDirection(event);
      gettimeofday(&after, NULL);
      timeval_diff(&interval, &after, &before);
      if (interval.tv_sec > 0 || interval.tv_usec > (TIME / speed))
	{
	  this->move();
	  gettimeofday(&before, NULL);
	}
    }
}

int Game::displayGameOver()
{
  int ac = 0;
  char *av[1] = {(char*) "Something"};

  QApplication app(ac, av);
  MyWidget widget(_score);

  widget.show();

  return app.exec();
}
