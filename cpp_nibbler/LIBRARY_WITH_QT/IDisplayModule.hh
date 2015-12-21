//
// IDisplayModule.hh for IDisplayModule in /home/garcia_t/rendu/cpp_nibbler
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Tue Mar 24 14:53:56 2015 antoine garcia
// Last update Fri Apr  3 13:16:12 2015 Nicolas Charvoz
//

#ifndef _IDISPLAYMODULE_HH_
# define _IDISPLAYMODULE_HH_
#include <list>
#include "struct.h"
#include "Apple.hpp"
#include <string>
class	IDisplayModule
{
public:
  virtual void init(int, int) = 0;
  virtual t_key  getEvent() = 0;
  virtual void draw(std::list<Coord>, std::list<Apple>&) = 0;
  virtual ~IDisplayModule(){}
  virtual void drawScore(const int) = 0;
};

#endif
