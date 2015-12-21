//
// Margarita.cpp for Margarita in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat Apr 18 05:12:52 2015 Antoine Garcia
// Last update Fri Apr 24 10:42:34 2015 Antoine Garcia
//

#include "Margarita.hh"
#include "../ingredient/Tomato.hh"
#include "../ingredient/Doe.hh"
#include "../ingredient/Gruyere.hh"

Margarita::Margarita(APizza::TaillePizza size)
{
	_ingredients.push_back(new Doe(1));
	_ingredients.push_back(new Tomato(1));
	_ingredients.push_back(new Gruyere(1));
	_time = 1;
	this->_size = size;
	_name = "Margarita";
}

Margarita::~Margarita(){}

int	Margarita::getTime() const
{
  return (_time);
}

const std::string &Margarita::getName() const
{
  return _name;
}

APizza::TaillePizza Margarita::getSize() const
{
  return _size;
}

const std::vector<AIngredient *>& Margarita::getIngredients() const
{
  return (_ingredients);
}
