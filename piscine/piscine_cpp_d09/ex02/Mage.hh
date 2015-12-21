//
// Mage.hh for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 14:42:43 2015 Nicolas Charvoz
// Last update Thu Jan 15 15:06:14 2015 Nicolas Charvoz
//

#ifndef MAGE_HH_
#define MAGE_HH_

#include <string>
#include <iostream>
#include "Character.hh"

class Mage : public Character {

public:
  Mage(const std::string &, int);
  int CloseAttack();
  int RangeAttack();
  void RestorePower();
private:
  bool _attackMage;

};

#endif
