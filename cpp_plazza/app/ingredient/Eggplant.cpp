#include "Eggplant.hh"

Eggplant::Eggplant(int nbItems)
{
  this->_nbItems = nbItems;
  _type = EGGPLANT;
}

Eggplant::~Eggplant(){}

int	Eggplant::getNbItems() const
{
  return (_nbItems);
}

void	Eggplant::addItem()
{
  _nbItems++;
}

void	Eggplant::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Eggplant::getType() const
{
  return (_type);
}
