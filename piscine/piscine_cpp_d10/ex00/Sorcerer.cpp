//
// Sorcerer.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 10:06:40 2015 Nicolas Charvoz
// Last update Fri Jan 16 11:18:04 2015 Nicolas Charvoz
//

#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
  std::cout << _name << ", " << _title
	    << ", is born !" <<std::endl;
}

Sorcerer::~Sorcerer()
{
  std::cout << _name << ", " << _title
	    << ", is dead. Consequences will never be the same !" <<std::endl;
}

std::string Sorcerer::getName()
{
  return _name;
}

std::string Sorcerer::getTitle()
{
  return _title;
}

std::ostream &operator<<(std::ostream &os, Sorcerer &s)
{
  return os << "I am "<< s.getName()
	    << ", " << s.getTitle()
	    << ", and I like ponies !" << std::endl;
}

void Sorcerer::polymorph(Victim const &v) const
{
  v.getPolymorphed();
}
