//
// Priest.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 15:10:38 2015 Nicolas Charvoz
// Last update Thu Jan 15 17:18:25 2015 Nicolas Charvoz
//

#include "Priest.hh"

Priest::Priest(const std::string &name, int level) : Mage(name, level)
{
  _pV = 100;
  _power = 100;
  _strength = 4;
  _stamina = 4;
  _intelligence = 42;
  _spirit = 21;
  _agility = 2;
  _race = "Orc";

  std::cout << _name << " enters in the order" <<std::endl;
}

int Priest::CloseAttack()
{
  int damage = 0;

  if (_power >= 10)
    {
      _power -= 10;
      damage = 10 + _spirit;
      std::cout << _name << " uses a spirit explosion"
		<< std::endl;
    }
  else
    std::cout << _name << " out of power" << std::endl;

  return damage;
}

int Priest::RangeAttack()
{
  int damage = 0;

  if (_power >= 25)
    {
      _power -= 25;
      damage = 20 + _spirit;
      std::cout << _name << " launches a fire ball" <<std::endl;
    }
  else
    std::cout << _name << " out of power" << std::endl;

  return damage;
}

void Priest::Heal()
{
  if (_power >= 10)
    {
      _power -= 10;
      if (_pV <= 30)
	_pV += 70;
      else
	_pV = 100;
      std::cout << _name << " casts a little heal spell"
		<<std::endl;
    }
}
