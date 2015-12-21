//
// Paladin.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 17:05:54 2015 Nicolas Charvoz
// Last update Thu Jan 15 18:11:44 2015 Nicolas Charvoz
//

#include "Paladin.hh"

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Mage(name, level), Priest(name, level)
{
  _strength = 9;
  _stamina = 10;
  _intelligence = 10;
  _spirit = 10;
  _agility = 2;
  _weaponName = "hammer";
  std::cout << "the light falls on " << _name<<std::endl;
}

int Paladin::CloseAttack()
{
  return Warrior::CloseAttack();
}

int Paladin::RangeAttack()
{
  return Priest::RangeAttack();
}

void Paladin::Heal()
{
  Priest::Heal();
}

int Paladin::Intercept()
{
  if (_power >= 10)
    {
      _power -= 10;
      std::cout << _name << " intercepts" <<std::endl;
      Range = Character::CLOSE;
    }
  else
    std::cout << _name << " out of power" <<std::endl;

  return 0;
}
