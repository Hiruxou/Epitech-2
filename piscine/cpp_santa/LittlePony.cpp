//
// LittlePony.cpp for rush in /home/audibe_l/rendu/cpp_santa
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Sat Jan 17 09:34:03 2015 Audibert Louis
// Last update Sat Jan 17 23:33:03 2015 Nicolas Charvoz
//

#include "LittlePony.hh"

LittlePony::LittlePony(std::string const &name): Toy(name, LITTLEPONY)
{
}

LittlePony::LittlePony(LittlePony const &pony): Toy(pony._name, LITTLEPONY)
{

}

LittlePony::~LittlePony()
{

}

void	LittlePony::isTaken() const
{
  std::cout << "yo man" << std::endl;
}
