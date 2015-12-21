//
// Americaine.cpp for plazza in /home/heitzl_s/rendu/cpp_plazza/app/pizza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:01:02 2015 Serge Heitzler
// Last update Fri Apr 24 10:42:20 2015 Antoine Garcia
//

#include "Americaine.hh"
#include "../ingredient/Doe.hh"
#include "../ingredient/Tomato.hh"
#include "../ingredient/Gruyere.hh"
#include "../ingredient/Steak.hh"

Americaine::Americaine(APizza::TaillePizza size)
{
	_ingredients.push_back(new Doe(1));
	_ingredients.push_back(new Tomato(1));
	_ingredients.push_back(new Gruyere(1));
	_ingredients.push_back(new Steak(1));
	_time = 2;
	this->_size = size;
	_name = "Americaine";
}

Americaine::~Americaine(){}

int	Americaine::getTime() const
{
  return (_time);
}

const std::string &Americaine::getName() const
{
  return _name;
}

APizza::TaillePizza Americaine::getSize() const
{
  return _size;
}

const std::vector<AIngredient *>& Americaine::getIngredients() const
{
  return (_ingredients);
}
