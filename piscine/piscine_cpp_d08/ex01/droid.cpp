//
// droid.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:40:04 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:40:05 2015 Nicolas Charvoz
//

#include "droid.hh"

Droid::Droid(std::string id) : id(id), energy(50), attack(25), toughness(15)
{
  status = new std::string("Standing by");
  battleData = new DroidMemory();
  output("Activated");
}

Droid::Droid(Droid const & droid) : id(droid.id), energy(droid.energy), attack(droid.attack), toughness(droid.toughness)
{
  if (droid.status)
    status = new std::string(*(droid.status));
  else
    status = new std::string("Standing by");
  output("Activated, Memory Dumped");
}

Droid::~Droid()
{
  if (status)
    delete status;
  output("Destroyed");
}

std::string		Droid::getId() const
{
  return id;
}

size_t			Droid::getEnergy() const
{
  return energy;
}

size_t			Droid::getAttack() const
{
  return attack;
}

size_t			Droid::getToughness() const
{
  return toughness;
}

std::string*		Droid::getStatus() const
{
  return status;
}

DroidMemory*		Droid::getBattleData() const
{
  return battleData;
}

void			Droid::setId(std::string id)
{
  this->id = id;
}

void			Droid::setEnergy(size_t energy)
{
  this->energy = energy;
}

void			Droid::setStatus(std::string* status)
{
  if (this->status)
    delete this->status;
  this->status = status;
}

void			Droid::setBattleData(DroidMemory* memory)
{
  delete battleData;
  battleData = memory;
}

Droid&			Droid::operator=(Droid const & droid)
{
  id = droid.id;
  energy = droid.energy;
  delete status;
  status = new std::string(*(droid.status));
  return *this;
}

bool			Droid::operator ==(Droid const & droid) const
{
  return *status == *(droid.status);
}

bool			Droid::operator !=(Droid const & droid) const
{
  return (!(*this == droid));
}

Droid&			Droid::operator <<(size_t & energy)
{
  if (this->energy < 100)
    {
      int take = std::min(100 - this->energy, energy);
      this->energy += take;
      energy -= take;
    }
  return *this;
}

void			Droid::output(std::string message)
{
  std::cout << "Droid '" << id << "' " << message << std::endl;
}

std::ostream &		operator<<(std::ostream & os, Droid const & droid)
{
  return (os << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy());
}
