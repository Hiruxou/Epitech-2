//
// Mage.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 14:44:43 2015 Nicolas Charvoz
// Last update Thu Jan 15 15:09:08 2015 Nicolas Charvoz
//

#include "Mage.hh"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
  _pV = 100;
  _power = 100;
  _strength = 6;
  _stamina = 6;
  _intelligence = 12;
  _spirit = 11;
  _agility = 7;
  _race = "Gnome";
  _attackMage = false;
  std::cout << _name << " teleported" <<std::endl;
}

int Mage::CloseAttack()
{
  int damage = 0;

  if (_attackMage == false)
    {
      if (_power >= 10)
	{
	  _power -= 10;
	  damage = 0;
	  std::cout << _name << " blinks" <<std::endl;
	}
      else
	std::cout << _name << " out of power" << std::endl;
      _attackMage = true;
    }
  return damage;
}

int Mage::RangeAttack()
{
  int damage = 0;

  if (_attackMage == true) {
    if (_power >= 25)
      {
	_power -= 25;
	damage = 20 + _spirit;
      std::cout << _name << " launches a fire ball" <<std::endl;
      }
    else
      std::cout << _name << " out of power" << std::endl;
    _attackMage = false;
  }
  return damage;
}

void Mage::RestorePower()
{
  if (_power >= 50 + _intelligence)
    _power += 50 + _intelligence ;
  else
    _power = 100;
  std::cout << _name << " takes a mana potion"<<std::endl;
}
