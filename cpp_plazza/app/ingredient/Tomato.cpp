#include "Tomato.hh"

Tomato::Tomato(int nbItems)
{
  _type = TOMATO;
  this->_nbItems = nbItems;
}

Tomato::~Tomato(){}

int	Tomato::getNbItems() const
{
  return (_nbItems);
}

void	Tomato::addItem()
{
  _nbItems++;
}

void	Tomato::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Tomato::getType() const
{
  return (_type);
}
