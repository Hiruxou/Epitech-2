//
// Borg.hh for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 10:52:31 2015 Nicolas Charvoz
// Last update Tue Jan 13 12:48:36 2015 Nicolas Charvoz
//

#ifndef BORG_HH_
#define BORG_HH_

#include <string>
#include <iostream>
#include "Warpsystem.hh"
#include "Destination.hh"

namespace Borg {
  class Ship {
  private:
    int _side;
    short _maxWarp;
    WarpSystem::Core *Core;
    Destination _location;
    Destination _home;
  public:
    Ship();
    ~Ship();
    void setupCore(WarpSystem::Core*);
    void checkCore();
    bool move(int, Destination);
    bool move(int);
    bool move(Destination);
    bool move();
  };
};

#endif
