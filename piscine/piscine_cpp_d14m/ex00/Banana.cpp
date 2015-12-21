//
// Banana.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d14m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 10:28:13 2015 Nicolas Charvoz
// Last update Tue Jan 20 10:29:27 2015 Nicolas Charvoz
//

#include "Banana.h"

Banana::Banana() : Fruit("banana", 5) {}

int Banana::getVitamins() const {
  return _vitamins;
}

std::string const &Banana::getName() const {
  return _name;
}
