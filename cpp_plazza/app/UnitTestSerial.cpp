//
// UnitTestSerial.cpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Apr 23 13:03:54 2015 Nicolas Charvoz
// Last update Thu Apr 23 14:34:44 2015 Nicolas Charvoz
//

#include "Serializer.hpp"

int		main(int ac, char **av)
{
  std::string s;
  Serializer serial;
  std::list<Parser::t_pizza> list;

  s = "MARGARITA XL X9;MARGARITA XL X10;";
  std::cout << "UNPACK INPUT: " << std::endl;
  std::cout << s << std::endl;
  list = serial.unpack(s);
  std::cout << "PACK OUTPUT: " << std::endl;
  std::cout << serial.pack(list) << std::endl;
  return (0);
}
