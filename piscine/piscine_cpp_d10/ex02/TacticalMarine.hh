//
// TacticalMarine.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 16:46:00 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:46:23 2015 Nicolas Charvoz
//

#ifndef TACTICALMARINE_HH
#define TACTICALMARINE_HH

#include <string>
#include <iostream>
#include "ISpaceMarine.hh"

class TacticalMarine : public ISpaceMarine {

protected:

  void speak(std::string message) const;

public:

  TacticalMarine();
  TacticalMarine(TacticalMarine const & marine);
  virtual ~TacticalMarine();
  virtual ISpaceMarine *clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;
};

#endif
