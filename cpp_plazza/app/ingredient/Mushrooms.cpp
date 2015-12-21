#include "Mushrooms.hh"

Mushrooms::Mushrooms(int nbItems)
{
  _type = MUSHROOMS;
  this->_nbItems = nbItems;
}

Mushrooms::~Mushrooms(){}

int	Mushrooms::getNbItems() const
{
  return (_nbItems);
}

void	Mushrooms::addItem()
{
  _nbItems++;
}

void	Mushrooms::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Mushrooms::getType() const
{
  return (_type);
}
