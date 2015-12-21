//
// AEnemy.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 14:46:18 2015 Nicolas Charvoz
// Last update Fri Jan 16 20:51:03 2015 Nicolas Charvoz
//

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
}

AEnemy::~AEnemy() {}

std::string const &AEnemy::getType() const {
  return _type;
}

int AEnemy::getHP() const
{
  return _hp;
}

void AEnemy::takeDamage(int damage)
{
  if (damage > 0) {
      _hp -= damage;
    }
}
