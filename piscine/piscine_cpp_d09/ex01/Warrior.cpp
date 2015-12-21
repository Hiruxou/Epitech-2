//
// Warrior.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 13:14:52 2015 Nicolas Charvoz
// Last update Thu Jan 15 16:03:30 2015 Nicolas Charvoz
//

#include "Warrior.hh"

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
  _strength = 12;
  _stamina = 12;
  _intelligence = 6;
  _agility = 7;
  _spirit = 5;
  _pV = 100;
  _power = 100;
  _race = "Dwarf";
  _attack = true;
  _weaponName = "hammer";
  Range = Character::CLOSE;
  std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack()
{
  int damage = 0;

  if (_attack == false) {
    if (_power >= 30)
      {
	_power -= 30;
	damage = 20 + _strength;
	std::cout << _name << " strikes with his "
		  << _weaponName << std::endl;
      }
    else
      std::cout << _name << " out of power" << std::endl;
  }
  return damage;
}

int Warrior::RangeAttack()
{
  int damage = 0;

  if (_attack == true)
    {
      if (_power >= 10)
	{
	  _power -= 10;
	  damage = 0;
	  std::cout << _name << " intercepts" <<std::endl;
	  Range = Character::CLOSE;
	}
      else
	std::cout << _name << " out of power" << std::endl;
      _attack = false;
    }
  return damage;
}
