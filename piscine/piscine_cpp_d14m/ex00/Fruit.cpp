//
// Fruit.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d14m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 09:59:30 2015 Nicolas Charvoz
// Last update Tue Jan 20 10:23:29 2015 Nicolas Charvoz
//

#include "Fruit.h"

Fruit::Fruit(std::string const &name, int vitamins)
  : _name(name), _vitamins(vitamins)
{}

Fruit::~Fruit() {}

Fruit::Fruit(Fruit const &f) {
  _vitamins = f._vitamins;
  _name = f._name;
}
