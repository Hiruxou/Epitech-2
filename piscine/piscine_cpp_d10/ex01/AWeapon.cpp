//
// AWeapon.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 11:39:49 2015 Nicolas Charvoz
// Last update Fri Jan 16 14:38:24 2015 Nicolas Charvoz
//

#include "AWeapon.hh"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage)
{
}

AWeapon::~AWeapon(){}

std::string const &AWeapon::getName() const
{
  return _name;
}

int AWeapon::getAPCost() const
{
  return _apcost;
}

int AWeapon::getDamage() const
{
  return _damage;
}
