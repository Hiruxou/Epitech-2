//
// Toy.cpp for ex00 in /home/nicolas/rendu/cpp_santa
// 
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
// 
// Started on  Sat Jan 17 09:27:45 2015 Nicolas Girardot
// Last update Sat Jan 17 10:01:34 2015 Nicolas Girardot
//

#include "Toy.hh"

Toy::Toy(std::string const &name, int type) : Object(name, type)
{
}

Toy::Toy(Toy const &o) : Object(o._name, o._type)
{
}

Toy::~Toy() {}

void	Toy::isTaken() const 
{
}
