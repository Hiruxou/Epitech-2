#include "Doe.hh"

Doe::Doe(int nbItems)
{
  this->_nbItems = nbItems;
  _type = DOE;
}

Doe::~Doe(){}

int	Doe::getNbItems() const
{
  return (_nbItems);
}

void	Doe::addItem()
{
  _nbItems++;
}

void	Doe::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Doe::getType() const
{
  return (_type);
}
