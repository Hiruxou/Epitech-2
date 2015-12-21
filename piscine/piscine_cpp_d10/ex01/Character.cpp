//
// Character.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 15:21:26 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:08:30 2015 Nicolas Charvoz
//

#include "Character.hh"

Character::Character(std::string const &name) : _name(name), _ap(40), _currentWeapon(NULL)
{
}

Character::~Character()
{
}

void Character::recoverAP()
{
  _ap += 10;
  if (_ap > 40)
    _ap = 40;
}

void Character::equip(AWeapon *weapon)
{
  _currentWeapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
  if (_currentWeapon && enemy)
    {
      if (action(_currentWeapon->getAPCost()))
	{
	  std::cout << _name << " attacks " << enemy->getType()
		    << " with a " << _currentWeapon->getName()
		    << std::endl;
	  _currentWeapon->attack();
	  enemy->takeDamage(_currentWeapon->getDamage());
	  if (enemy->getHP() <= 0)
	    {
	      delete enemy;
	    }
	}
    }
}

bool Character::action(int cost)
{
  if (_ap >= cost)
    {
      _ap -= cost;
      return true;
    }
  return false;
}

std::string const &Character::getName() const
{
  return _name;
}

int Character::getAP() const
{
  return _ap;
}

AWeapon *Character::getWeapon() const
{
  return _currentWeapon;
}

std::ostream &operator<<(std::ostream &os, Character const &c)
{
  os << c.getName() << " has " << c.getAP() << " AP and ";
  if (c.getWeapon())
    os << "wields a " << c.getWeapon()->getName();
  else
    os << "is unarmed";
  os << std::endl;
  return os;
}
