//
// Priest.hh for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 15:09:20 2015 Nicolas Charvoz
// Last update Thu Jan 15 17:40:35 2015 Nicolas Charvoz
//

#ifndef PRIEST_HH_
#define PRIEST_HH_

#include <string>
#include <iostream>
#include "Mage.hh"

class Priest : virtual public Mage {
public:
  Priest(const std::string &, int);
  int CloseAttack();
  int RangeAttack();
  void Heal();
};

#endif
