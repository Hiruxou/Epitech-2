//
// Borg.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 10:53:27 2015 Nicolas Charvoz
// Last update Tue Jan 13 15:15:13 2015 Nicolas Charvoz
//

#include "Borg.hh"

Borg::Ship::Ship(int wF, short repair)
{
  this->_side = 300;
  this->_maxWarp = 9;
  this->_weaponFrequency = wF;
  this->_repair = repair;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally."
	    <<std::endl
	    <<"Your biological characteristics and technologies will be assimilated."
	    <<std::endl
	    << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *_core)
{
  this->Core = _core;
}

void Borg::Ship::checkCore()
{
  if (this->Core->checkReactor()->isStable() == true)
    std::cout << "Everything is in order." <<std::endl;
  else
    std::cout << "Critical failure imminent." <<std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
  this->_location = d;
  if (warp <= this->_maxWarp || d != this->_location || this->Core->checkReactor()->isStable() == true)
    return true;
  return false;
}

bool Borg::Ship::move(int warp)
{
  this->_location = this->_home;
  if (warp <= this->_maxWarp || this->Core->checkReactor()->isStable() == true)
    return true;
  return false;
}

bool Borg::Ship::move(Destination d)
{
  this->_location = d;
  if (d != this->_location || this->Core->checkReactor()->isStable() == true)
    return true;
  return false;
}

bool Borg::Ship::move()
{
  this->_location = this->_home;
  if (this->Core->checkReactor()->isStable() == true)
    return true;
  return false;
}

int Borg::Ship::getShield()
{
  return this->_shield;
}

void Borg::Ship::setShield(int shield)
{
  this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
  return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int wF)
{
  this->_weaponFrequency = wF;
}

short Borg::Ship::getRepair()
{
  return this->_repair;
}

void Borg::Ship::setRepair(int repair)
{
  this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *ship)
{
  ship->setShield(ship->getShield() - this->_weaponFrequency);
  std::cout << "Firing on target with " <<  this->_weaponFrequency << "GW frequency." <<std::endl;
}

void Borg::Ship::fire(Federation::Ship *ship)
{
  ship->getCore()->checkReactor()->setStability(false);
}

void Borg::Ship::repair()
{
  if (this->_repair > 0)
    {
      std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
      this->_repair -= 1;
      this->_shield = 100;
    }
  else
    std::cout << "Energy cells depleted, shield weakening." <<std::endl;
}
