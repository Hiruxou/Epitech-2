//
// Apple.hpp for  in /home/nicolaschr/rendu/cpp_nibbler
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Apr  2 16:03:01 2015 Nicolas Charvoz
// Last update Fri Apr  3 05:13:39 2015 Antoine Garcia
//

#ifndef APPLE_HPP_
# define APPLE_HPP_

#include <iostream>
#include <string>
#include "struct.h"

typedef enum {
  NORMAL_APPLE,
  BIG_APPLE
} e_apple;

class Apple {

  public:
  Apple() {
    _value = 10;
    _type = NORMAL_APPLE;
    _pos = Coord(0, 0);
  }
  ~Apple() {}
  int getValue() const
  {
    return _value;
  }
  e_apple getType() const {
    return _type;
  }
  Coord getCoord() const {
    return _pos;
  }
  void	setType(e_apple type) {
    _type = type;
  }
  void	setCoord(Coord coord) {
    _pos = coord;
  }
  void	setValue(int value) {
    _value = value;
  }

private:
  int _value;
  e_apple _type;
  Coord _pos;
};

#endif
