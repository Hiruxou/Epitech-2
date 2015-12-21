//
// Regina.cpp for plazza in /home/heitzl_s/rendu/cpp_plazza/app/pizza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 14:57:22 2015 Serge Heitzler
// Last update Fri Apr 24 10:43:03 2015 Antoine Garcia
//

#include "Regina.hh"
#include "../ingredient/Doe.hh"
#include "../ingredient/Tomato.hh"
#include "../ingredient/Gruyere.hh"
#include "../ingredient/Ham.hh"
#include "../ingredient/Mushrooms.hh"

Regina::Regina(APizza::TaillePizza size)
{
  _ingredients.push_back(new Doe(1));
  _ingredients.push_back(new Tomato(1));
  _ingredients.push_back(new Gruyere(1));
  _ingredients.push_back(new Ham(1));
  _ingredients.push_back(new Mushrooms(1));
  _time = 2;
  this->_size = size;
  _name = "Regina";
}

Regina::~Regina(){}

int	Regina::getTime() const
{
  return (_time);
}

const std::string &Regina::getName() const
{
  return _name;
}

APizza::TaillePizza Regina::getSize() const
{
  return _size;
}

const std::vector<AIngredient *>& Regina::getIngredients() const
{
  return (_ingredients);
}
