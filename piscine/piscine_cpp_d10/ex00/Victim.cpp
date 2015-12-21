//
// Victim.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 10:19:53 2015 Nicolas Charvoz
// Last update Fri Jan 16 11:16:03 2015 Nicolas Charvoz
//

#include "Victim.hh"

Victim::Victim(std::string name) : _name(name)
{
  std::cout << "Some random victim called "<< _name
	    << " just popped !" << std::endl;
}

std::string Victim::getName()
{
  return _name;
}

Victim::~Victim()
{
  std::cout << "Victim " << _name
	    << " just died for no apparent reason !" << std::endl;
}

std::ostream& operator<<(std::ostream &os, Victim &v)
{
  return os << "I'm " << v.getName() << " and i like otters !"<< std::endl;
}

void Victim::getPolymorphed() const
{
  std::cout << _name << " has been turned into a cute little sheep !"
	    <<std::endl;
}
