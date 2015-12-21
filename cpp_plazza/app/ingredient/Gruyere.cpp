#include "Gruyere.hh"

Gruyere::Gruyere(int nbItems)
{
  this->_nbItems = nbItems;
  _type = GRUYERE;
}

Gruyere::~Gruyere(){}

int	Gruyere::getNbItems() const
{
  return (_nbItems);
}

void	Gruyere::addItem()
{
  _nbItems++;
}

void	Gruyere::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Gruyere::getType() const
{
  return (_type);
}
