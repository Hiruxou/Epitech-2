//
// SuperMutant.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 14:52:26 2015 Nicolas Charvoz
// Last update Fri Jan 16 15:02:46 2015 Nicolas Charvoz
//

#ifndef SUPERMUTANT_HH_
#define SUPERMUTANT_HH_

#include <string>
#include <iostream>

#include "AEnemy.hh"

class SuperMutant : public AEnemy {

public:

  SuperMutant();
  ~SuperMutant();
  virtual void takeDamage(int);


};

#endif
