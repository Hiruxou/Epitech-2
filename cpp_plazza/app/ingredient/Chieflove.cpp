#include "Chieflove.hh"

Chieflove::Chieflove(int nbItems)
{
  this->_nbItems = nbItems;
  _type = CHIEFLOVE;
}

Chieflove::~Chieflove(){}

int	Chieflove::getNbItems() const
{
  return (_nbItems);
}

void	Chieflove::addItem()
{
  _nbItems++;
}

void	Chieflove::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Chieflove::getType() const
{
  return (_type);
}
