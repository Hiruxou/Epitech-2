//
// Character.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 10:54:52 2015 Nicolas Charvoz
// Last update Thu Jan 15 13:25:30 2015 Nicolas Charvoz
//

#include "Character.hh"

Character::Character(const std::string &name, int level) : _name(name), _level(level), _pV(100), _power(100), _strength(5), _stamina(5), _intelligence(5), _spirit(5), _agility(5), _race("Koala"), Range(CLOSE)
{
  std::cout << _name << " Created"<<std::endl;
}

const std::string &Character::getName() const {
  return _name;
}

int Character::getLvl() const  {
  return _level;
}

int Character::getPv() const  {
  return _pV;
}

int Character::getPower() const  {
  return _power;
}

int Character::CloseAttack()
{
  int damage = 0;

  if (_power >= 10)
    {
      _power -= 10;
      damage = 10 + _strength;
      std::cout << _name
		<< " strikes with a wood stick" << std::endl;
    }
  else
    std::cout << _name << " out of power" << std::endl;
  return damage;
}

int Character::RangeAttack()
{
  int damage = 0;

  if (_power >= 10) {
    _power -= 10;
    damage = 5 + _strength;
    std::cout << _name << " launches a stone" << std::endl;
  }
  else
    std::cout << _name << " out of power" << std::endl;
  return damage;
}

void Character::Heal()
{
  (_pV <= 50) ? (_pV += 50) : (_pV = 100);
  std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
  _power = 100;
  std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int _damage)
{

  if (_pV - _damage <= 0)
    std::cout << _name << " out of combat" <<std::endl;
  else
    std::cout << _name << " takes "
	    << _damage << " damage"<<std::endl;
}
