//
// Peon.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 10:56:29 2015 Nicolas Charvoz
// Last update Fri Jan 16 11:20:09 2015 Nicolas Charvoz
//

#include "Peon.hh"

Peon::Peon(std::string name) : Victim(name)
{
  std::cout << "Zog zog." <<std::endl;
}

Peon::~Peon()
{
  std::cout << "Bleuark..." <<std::endl;
}

void Peon::getPolymorphed() const
{
  std::cout << _name << " has been turned into a pink pony !" <<std::endl;
}
