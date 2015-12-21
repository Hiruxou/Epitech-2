//
// droid.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Jan 14 10:50:04 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:56:31 2015 Nicolas Charvoz
//

#include "droid.hh"
#include <algorithm>

void Droid::setId(std::string id)
{
  this->Id = id;
}

std::string Droid::getId() const
{
  return this->Id;
}

void Droid::setEnergy(size_t energy)
{
  this->Energy = energy;
}

size_t Droid::getEnergy() const
{
  return this->Energy;
}

std::string *Droid::getStatus() const
{
  return this->Status;
}

void Droid::setStatus(std::string *Status)
{
  this->Status = Status;
}

size_t Droid::getAttack() const
{
  return this->Attack;
}

size_t Droid::getToughness() const
{
  return this->Toughness;
}

bool Droid::operator==(Droid const& one) const
{
  if ((this->Id.compare(one.Id) == 0)
      && this->Energy == one.Energy
      && this->Attack == one.Attack
      && this->Toughness == one.Toughness
      && (this->Status->compare(*(one.Status)) == 0))
      return true;
  return false;
}

bool Droid::operator!=(Droid const& one) const
{
  return !(*this == one);
}

Droid &Droid::operator<<(size_t& stock)
{
  if (Energy + stock >= 100)
    {
      stock = stock - (100 - Energy);
      Energy = 100;
    }
  else
    {
      Energy = Energy + stock;
      stock = 0;
    }
  return *this;
}

Droid &Droid::operator=(Droid const& one)
{
  this->Id = one.Id;
  this->Energy = one.Energy;
  Status = new std::string(*(one.Status));

  return *this;
}

std::ostream& operator<<(std::ostream &os, Droid const &d)
{
  return (os << "Droid '" << d.getId() <<"', "
	  << *(d.getStatus())
	  << ", "
	  << d.getEnergy());
}

Droid::Droid(Droid const &one) : Id(one.Id), Energy(one.Energy), Attack(one.Attack), Toughness(one.Toughness)
{
  if (one.Status)
    {
      this->Status = new std::string(*(one.Status));
    }
  else
    this->Status = new std::string("Standing by");
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::Droid(std::string id) : Id(id), Energy(50), Attack(25), Toughness(15)
{
  this->Status = new std::string("Standing by");
  std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::~Droid()
{
  std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}
