//
// Federation.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 09:27:15 2015 Nicolas Charvoz
// Last update Tue Jan 13 20:12:26 2015 Nicolas Charvoz
//

#include "Federation.hh"
#include "Borg.hh"

//Class Ship inside Starfleet inside Federation

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_home = EARTH;
  this->_location = this->_home;
  this->_shield = 100;
  this->_photonTorpedo = torpedo;
  std::cout <<"The ship USS "<<name<<" has been finished. It is "<<length<<" m in length and "<< width <<" m in width."
	    << "It can go to Warp "
	    << maxWarp <<"!"<<std::endl;;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *_core)
{
  this->Core = _core;
  std::cout << "USS " << this->_name <<": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
  if (this->Core->checkReactor()->isStable() == true)
    {
      std::cout << "USS " << this->_name << ": The core is "
		<< "stable"
		<< " at the time." << std::endl;
    }
  else {
    std::cout << "USS " << this->_name << ": The core is "
	      << "unstable"
	      << " at the time." << std::endl;
  }
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
  this->_location = d;
  if (warp <= this->_maxWarp || d != this->_location || this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
  this->_location = this->_home;
  if (warp <= this->_maxWarp || this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
  this->_location = d;
  if (d != this->_location || this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

bool Federation::Starfleet::Ship::move()
{
  this->_location = this->_home;
  if (this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *borg)
{
  if (this->_photonTorpedo >= 1)
    {
      borg->setShield(getShield() - 50);
      std::cout << this->_name << ": Firing on target. "<< this->_photonTorpedo - 1 << " torpedoes remaining."<<std::endl;
    }
  else
    {
      std::cout << this->_name << ": No more torpedo to fire, " << this->captain->getName() << "!" <<std::endl;
    }

}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *borg)
{
  if (this->_photonTorpedo > torpedoes)
    {
      borg->setShield(getShield() - 50*torpedoes);
      std::cout << this->_name << ": Firing on target. "<< this->_photonTorpedo - torpedoes << " torpedoes remaining."<<std::endl;
    }
  else
    {
      std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" <<std::endl;
    }
}

//Class Ship inside Federation

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = 1;
  std::cout <<"The independant ship "<<name<<" just finished his construction. It is "<<length<<" m in length and "<< width <<" m in width."<<std::endl;

  std::cout<< "It can go to Warp "<< this->_maxWarp <<"!"<<std::endl;;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *_core)
{
  this->Core = _core;
  std::cout << this->_name <<": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
  if (this->Core->checkReactor()->isStable() == true)
    {
      std::cout << this->_name << ": The core is "
		<< "stable"
		<< " at the time." << std::endl;
    }
  else {
    std::cout << this->_name << ": The core is "
	      << "unstable"
	      << " at the time." << std::endl;
  }
}

bool Federation::Ship::move(int warp, Destination d)
{
  this->_location = d;
  if (warp <= this->_maxWarp || d != this->_location || this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

bool Federation::Ship::move(int warp)
{
  this->_location = this->_home;
  if (warp <= this->_maxWarp || this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

bool Federation::Ship::move(Destination d)
{
  this->_location = d;
  if (d != this->_location || this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

bool Federation::Ship::move()
{
  this->_location = this->_home;
  if (this->Core->checkReactor()->isStable() == true)
    return true ;
  return false;
}

WarpSystem::Core *Federation::Ship::getCore()
{
  return this->Core;
}

//Captain class inside starfleet inside federation

Federation::Starfleet::Captain::Captain(std::string name)
{
  this->_name = name;
}

Federation::Starfleet::Captain::~Captain(){}

std::string Federation::Starfleet::Captain::getName()
{
  return this->_name;
}

int Federation::Starfleet::Captain::getAge()
{
  return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
  this->_age = age;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
  this->captain = captain;
  std::cout << this->captain->getName() << ": I'm glad to be the captain of the USS " << this->_name<< "."<<std::endl;
}

int Federation::Starfleet::Ship::getShield()
{
  return this->_shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
  this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
  return this->_photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
  this->_photonTorpedo = torpedo;
}

// Ensign class

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  this->_name = name;
  std::cout << "Ensign " << this->_name
	    << ", awaiting orders." <<std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}
