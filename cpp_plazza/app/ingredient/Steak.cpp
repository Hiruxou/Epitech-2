#include "Steak.hh"

Steak::Steak(int nbItems)
{
  _type = STEAK;
  this->_nbItems = nbItems;
}

Steak::~Steak(){}

int	Steak::getNbItems() const
{
  return (_nbItems);
}

void	Steak::addItem()
{
  _nbItems++;
}

void	Steak::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Steak::getType() const
{
  return (_type);
}
