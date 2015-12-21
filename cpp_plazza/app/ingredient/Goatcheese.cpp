#include "Goatcheese.hh"

Goatcheese::Goatcheese(int nbItems)
{
  this->_nbItems = nbItems;
  _type = GOATCHEESE;
}

Goatcheese::~Goatcheese(){}

int	Goatcheese::getNbItems() const
{
  return (_nbItems);
}

void	Goatcheese::addItem()
{
  _nbItems++;
}

void	Goatcheese::takeItem()
{
  _nbItems--;
}

AIngredient::Ingredients	Goatcheese::getType() const
{
  return (_type);
}
