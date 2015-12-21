//
// Peon.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 10:56:27 2015 Nicolas Charvoz
// Last update Fri Jan 16 11:20:15 2015 Nicolas Charvoz
//

#ifndef PEON_HH_
#define PEON_HH_

#include <string>
#include <iostream>
#include "Victim.hh"

class Peon : public Victim {

public:
  Peon(std::string);
  virtual ~Peon();
  virtual void getPolymorphed() const;

private:


};

#endif
