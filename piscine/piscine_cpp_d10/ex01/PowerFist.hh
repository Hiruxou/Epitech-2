//
// PowerFist.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 14:33:10 2015 Nicolas Charvoz
// Last update Fri Jan 16 14:41:45 2015 Nicolas Charvoz
//

#ifndef POWERFIST_HH_
#define POWERFIST_HH_

#include <string>
#include <iostream>
#include "AWeapon.hh"

class PowerFist : public AWeapon {

public:

  PowerFist();
  ~PowerFist();

  virtual void attack() const;
};

#endif
