//
// Borg.hh for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 10:52:31 2015 Nicolas Charvoz
// Last update Tue Jan 13 15:08:59 2015 Nicolas Charvoz
//

#ifndef BORG_HH_
#define BORG_HH_

#include <string>
#include <iostream>
#include "Federation.hh"
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
    int _shield;
    int _weaponFrequency;
    short _repair;
  public:
    Ship(int, short repair = 3);
    ~Ship();
    void setupCore(WarpSystem::Core*);
    void checkCore();
    bool move(int, Destination);
    bool move(int);
    bool move(Destination);
    bool move();
    int getShield();
    void setShield(int);
    int getWeaponShield();
    void setWeaponFrequency(int);
    int getWeaponFrequency();
    void setWeaponShield(int);
    short getRepair();
    void setRepair(int);
    void fire(Federation::Starfleet::Ship *);
    void fire(Federation::Ship *);
    void repair();
  };
};

#endif
