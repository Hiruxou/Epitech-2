//
// ISpaceMarine.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 16:40:37 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:47:21 2015 Nicolas Charvoz
//

#ifndef ISPACEMARINE_HH_
#define ISPACEMARINE_HH_

class ISpaceMarine {

public:

  virtual ~ISpaceMarine() {}
  virtual ISpaceMarine *clone() const = 0;
  virtual void battleCry() const = 0;
  virtual void rangedAttack() const = 0;
  virtual void meleeAttack() const = 0;

};

#endif
