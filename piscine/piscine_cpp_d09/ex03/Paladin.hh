//
// Paladin.hh for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 17:05:56 2015 Nicolas Charvoz
// Last update Thu Jan 15 17:40:52 2015 Nicolas Charvoz
//

#ifndef PALADIN_HH_
#define PALADIN_HH_

#include <iostream>
#include <string>
#include "Priest.hh"
#include "Warrior.hh"

class Paladin : virtual public Warrior, virtual public Priest {

public:
  Paladin(const std::string &, int);
  int CloseAttack();
  int RangeAttack();
  void Heal();
  int Intercept();
};

#endif
