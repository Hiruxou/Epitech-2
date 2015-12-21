//
// Warrior.hh for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 13:13:20 2015 Nicolas Charvoz
// Last update Thu Jan 15 14:12:12 2015 Nicolas Charvoz
//

#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <string>
#include <iostream>
#include "Character.hh"

class Warrior : public Character {

private:

  std::string _weaponName;
  bool _attack;
public:
  Warrior(const std::string&, int);
  int CloseAttack();
  int RangeAttack();
};

#endif
