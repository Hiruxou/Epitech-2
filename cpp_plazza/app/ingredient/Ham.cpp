#include "Ham.hh"

Ham::Ham(int nbItems)
{
  _type = HAM;
  this->_nbItems = nbItems;
}

Ham::~Ham(){}

int	Ham::getNbItems() const
{
  return (_nbItems);
}

void	Ham::addItem()
{
  _nbItems++;
}

void	Ham::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Ham::getType() const
{
  return (_type);
}
