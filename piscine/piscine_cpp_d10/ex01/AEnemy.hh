//
// AEnemy.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 14:42:53 2015 Nicolas Charvoz
// Last update Fri Jan 16 14:48:37 2015 Nicolas Charvoz
//

#ifndef AENEMY_HH_
#define AENEMY_HH_

#include <string>
#include <iostream>

class AEnemy {

public:
  AEnemy(int hp, std::string const &type);
  virtual ~AEnemy();
  std::string const &getType() const;
  int getHP() const;
  virtual void takeDamage(int);

private:
  int _hp;
  std::string const _type;


};

#endif
