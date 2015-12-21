//
// Borg.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 10:53:27 2015 Nicolas Charvoz
// Last update Tue Jan 13 12:56:48 2015 Nicolas Charvoz
//

#include "Borg.hh"

Borg::Ship::Ship()
{
  this->_side = 300;
  this->_maxWarp = 9;
  this->_home = UNICOMPLEX;
  this->_location = this->_home;
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
