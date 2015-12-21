//
// Federation.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 09:27:15 2015 Nicolas Charvoz
// Last update Tue Jan 13 20:11:09 2015 Nicolas Charvoz
//

#include "Federation.hh"

//Class Ship inside Starfleet inside Federation

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  std::cout <<"The ship USS "<<name<<" has been finished. It is "<<length<<" m in length and "<< width <<" m in width."<<std::endl;

  std::cout<< "It can go to Warp "<< maxWarp <<"!"<<std::endl;;
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
