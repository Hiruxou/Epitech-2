//
// Lemon.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d14m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 10:21:24 2015 Nicolas Charvoz
// Last update Tue Jan 20 10:31:12 2015 Nicolas Charvoz
//

#include "Lemon.h"

Lemon::Lemon()
  : Fruit("lemon", 3) {}

int Lemon::getVitamins() const
{
  return _vitamins;
}

std::string const &Lemon::getName() const {
  return _name;
}
