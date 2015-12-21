//
// carrier.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:36:59 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:37:01 2015 Nicolas Charvoz
//

#include "carrier.hh"

Carrier::Carrier(std:: string id):Id(id), Energy(300), Attack(100), Toughness(90), Speed(0)
{
  droids = new Droid*[5];
  unsigned int i = 0;
  while (i < 5)
    {
      droids[i] = NULL;
      i++;
    }
}

Carrier::~Carrier()
{
  unsigned int i = 0;
  while (i < 5)
    {
      if (droids[i])
	{
	  delete droids[i];
	  droids[i] = NULL;
	}
      i++;
    }
}

size_t		Carrier::getEnergy() const
{
  return Energy;
}

void		Carrier::setEnergy(size_t energy)
{
  Energy = energy;
}

size_t		Carrier::getNbDroid() const
{
  int nb = 0;
  int i = 0;
  while (i < 5)
    {
      if (droids[i])
	nb++;
      i++;
    }
  return nb;
}

size_t	Carrier::getSpeed() const
{
  int nbDroids = this->getNbDroid();
  if (nbDroids)
    return 100 - (nbDroids * 10);
  return 0;
}

Carrier&	Carrier::operator<<(Droid *&droid)
{
  unsigned int	i = 0;

  while (i < 5)
    {
      if(droids[i] == NULL)
	{
	  droids[i] = droid;
	  droid = NULL;
	  return *this;
	}
      i++;
    }
  return *this;
}

Carrier&	Carrier::operator>>(Droid *&droid)
{
  unsigned int	i = 0;

  while (i < 5)
    {
      if (droids[i])
	{
	  droid = droids[i];
	  droids[i] = NULL;
	  return *this;
	}
      i++;
    }
  return *this;
}


Droid*&		Carrier::operator[](int position) const
{
  return droids[position];
}

Carrier&	Carrier::operator~()
{
  return *this;
}

bool	Carrier::operator()(int x, int y)
{
  size_t cost = (std::abs(x) + std::abs(y)) * (10 + getNbDroid());
  if (cost < Energy)
    {
      Energy -= cost;
      if (getSpeed() != 0)
	return true;
      else
	Energy = 0;
    }
  return false;
}

Carrier&	Carrier::operator<<(size_t& energy)
{
  if (Energy < 600) {
    int take = std::min(600 - Energy, energy);
    Energy += take;
    energy -= take;
  }
  return *this;
}

std::string	Carrier::getId() const
{
  return Id;
}
std::ostream&	operator<<(std::ostream& os, Carrier const &carrier)
{
  unsigned int i = 0;
  os << "Carrier '"<< carrier.getId() << "' Droid(s) on-board:" << std::endl;
  while (i < 5)
    {
      os << "[" << i << "] : ";
      if (carrier[i])
	os << *carrier[i];
      else
	os << "Free";
      i++;
      os << std::endl;
    }
  os << "Speed : " << carrier.getSpeed() <<", Energy " << carrier.getEnergy();
  return (os);
}
