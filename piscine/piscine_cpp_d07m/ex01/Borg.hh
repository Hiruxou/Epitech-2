//
// Borg.hh for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 10:52:31 2015 Nicolas Charvoz
// Last update Tue Jan 13 11:14:28 2015 Nicolas Charvoz
//

#ifndef BORG_HH_
#define BORG_HH_

#include <string>
#include <iostream>
#include "Warpsystem.hh"

namespace Borg {
  class Ship {
  private:
    int _side;
    short _maxWarp;
    WarpSystem::Core *Core;
  public:
    Ship();
    ~Ship();
    void setupCore(WarpSystem::Core*);
    void checkCore();
  };
};

#endif
