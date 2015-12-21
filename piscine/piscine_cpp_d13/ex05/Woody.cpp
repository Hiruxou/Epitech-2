//
// Woody.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 19 12:02:30 2015 Nicolas Charvoz
// Last update Mon Jan 19 15:20:55 2015 Nicolas Charvoz
//

#include "Woody.h"

Woody::Woody(std::string const &name, std::string const &file)
  : Toy(WOODY, name, file) {}

void Woody::speak(std::string const &statement)
{
  std::cout << "WOODY: " << _name << " \""
	    << statement << "\""<<std::endl;
}
