//
// Squad.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 16:44:42 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:45:05 2015 Nicolas Charvoz
//

#ifndef SQUAD_HH
#define SQUAD_HH

#include <string>
#include <iostream>

#include "ISquad.hh"
#include "ISpaceMarine.hh"

class Squad : public ISquad {

protected:

  int count;
  int size;
  ISpaceMarine **array;

public:

  Squad();
  Squad(Squad const & squad);
  virtual ~Squad();
  int getCount() const;
  ISpaceMarine *getUnit(int position);
  int push(ISpaceMarine *marine);
  Squad & operator=(Squad const & squad);

protected:

  void resize();

};

#endif
