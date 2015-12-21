//
// ISquad.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 16:31:31 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:37:31 2015 Nicolas Charvoz
//

#ifndef ISQUAD_HH_
#define ISQUAD_HH_

#include "ISpaceMarine.hh"

class ISquad {
public:

  virtual  ~ISquad()  {}
  virtual int getCount() const = 0;
  virtual ISpaceMarine *getUnit(int) = 0;
  virtual int push(ISpaceMarine*) = 0;

};

#endif
