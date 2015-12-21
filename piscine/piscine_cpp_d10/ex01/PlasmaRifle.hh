//
// PlasmaRifle.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 11:56:35 2015 Nicolas Charvoz
// Last update Fri Jan 16 14:41:05 2015 Nicolas Charvoz
//

#ifndef PLASMARIFLE_HH_
#define PLASMARIFLE_HH_

#include <string>
#include <iostream>
#include "AWeapon.hh"

class PlasmaRifle : public AWeapon {

public:

  PlasmaRifle();
  ~PlasmaRifle();
  virtual void attack() const;
};

#endif
