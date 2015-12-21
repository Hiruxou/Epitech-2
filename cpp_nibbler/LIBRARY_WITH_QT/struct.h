/*
** struct.h for struct in /home/antgar/rendu/cpp_nibbler
**
** Made by Antoine Garcia
** Login   <antgar@epitech.net>
**
** Started on  Thu Mar 26 14:27:17 2015 Antoine Garcia
** Last update Sat Apr  4 04:51:20 2015 Antoine Garcia
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef enum e_dir
  {
    UP,
    DOWN,
    LEFT,
    RIGHT,
  }	     t_dir;

typedef enum e_key
  {
    LEFT_KEY,
    RIGHT_KEY,
    ESC_KEY,
    SPACE_KEY,
    NONE
  }	     t_key;

class	Coord
{
 public:
  int	_y;
  int	_x;

 Coord():_y(0), _x(0)
    {}
 Coord(int y, int x):_y(y), _x(x)
  {}
  inline bool operator==(const Coord& b)
  {
    if (_x == b._x && _y == b._y)
      return (true);
    return (false);
  }
};

#endif
