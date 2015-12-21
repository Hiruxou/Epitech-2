//
// Buzz.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 19 11:17:17 2015 Nicolas Charvoz
// Last update Mon Jan 19 16:22:14 2015 Nicolas Charvoz
//

#include "Buzz.h"

Buzz::Buzz(std::string const &name, std::string const &file)
  : Toy(BUZZ, name, file)
{
}

bool Buzz::speak(std::string const &statement)
{
  std::cout << "BUZZ: " << _name << " \"" << statement << "\"" << std::endl;
  return true;
}

bool Buzz::speak_es(std::string const &statement)
{
  std::cout << "BUZZ: " << _name << " senorita \""
	    << statement << "\" senorita" << std::endl;
  return true;
}
