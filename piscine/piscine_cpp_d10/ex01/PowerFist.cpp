//
// PowerFist.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 14:34:23 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:13:26 2015 Nicolas Charvoz
//

#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist(){}

void PowerFist::attack() const {
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
