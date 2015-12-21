//
// AssaultTerminator.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 16:39:03 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:39:46 2015 Nicolas Charvoz
//

#ifndef ASSAULTTERMINATOR_HH_
#define ASSAULTTERMINATOR_HH_

#include <string>
#include <iostream>
#include "ISpaceMarine.hh"

class AssaultTerminator : public ISpaceMarine {

protected:
  void speak(std::string message) const;

public:

  AssaultTerminator();
  AssaultTerminator(AssaultTerminator const & marine);
  virtual ~AssaultTerminator();
  virtual ISpaceMarine *clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;

};
#endif
