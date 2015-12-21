//
// Teddy.cpp for rush in /home/audibe_l/rendu/cpp_santa
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Sat Jan 17 09:45:12 2015 Audibert Louis
// Last update Sat Jan 17 23:33:21 2015 Nicolas Charvoz
//

#include "Teddy.hh"

Teddy::Teddy(std::string const &name): Toy(name, TEDDY)
{
}

Teddy::Teddy(Teddy const &nounours): Toy(nounours._name, TEDDY)
{

}

Teddy::~Teddy()
{

}

void	Teddy::isTaken() const
{
  std::cout << "gra hu" << std::endl;
}
