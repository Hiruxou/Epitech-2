//
// Fantasia.cpp for plazza in /home/heitzl_s/rendu/cpp_plazza/app/pizza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 14:56:55 2015 Serge Heitzler
// Last update Fri Apr 24 10:42:09 2015 Antoine Garcia
//

#include "Fantasia.hh"
#include "../ingredient/Doe.hh"
#include "../ingredient/Tomato.hh"
#include "../ingredient/Eggplant.hh"
#include "../ingredient/Goatcheese.hh"
#include "../ingredient/Chieflove.hh"

Fantasia::Fantasia(APizza::TaillePizza size)
{
  _ingredients.push_back(new Doe(1));
  _ingredients.push_back(new Tomato(1));
  _ingredients.push_back(new Eggplant(1));
  _ingredients.push_back(new Goatcheese(1));
  _ingredients.push_back(new Chieflove(1));
  _time = 4;
  this->_size = size;
  _name = "Fantasia";
}

Fantasia::~Fantasia(){}

int	Fantasia::getTime() const
{
  return (_time);
}

const std::string &Fantasia::getName() const
{
  return _name;
}

APizza::TaillePizza Fantasia::getSize() const
{
  return _size;
}

const std::vector<AIngredient *>& Fantasia::getIngredients() const
{
  return (_ingredients);
}
