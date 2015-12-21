//
// droid.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:41:23 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:41:24 2015 Nicolas Charvoz
//

#include "droid.hh"

Droid::Droid(std::string id):Id(id), Energy(50), Attack(25), Toughness(15)
{
  this->Status = new std::string("Standing by");
  this->BattleData = new DroidMemory();
  std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
}

Droid::Droid(Droid const & droid):Id(droid.Id), Energy(droid.Energy), Attack(droid.Attack), Toughness(droid.Toughness)
{
  if (droid.Status)
    this->Status = new std::string(*(droid.Status));
  else
    this->Status = new std::string("Standing by");
  std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
  if (this->Status)
    delete this->Status;
  std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
}

void	Droid::setId(std::string newID)
{
  this->Id = newID;
}

std::string	Droid::getId() const
{
  return this->Id;
}

void	Droid::setEnergy(size_t newEnergy)
{
  this->Energy = newEnergy;
}

size_t	Droid::getEnergy() const
{
  return this->Energy;
}

size_t	Droid::getAttack() const
{
  return this->Attack;
}

size_t	Droid::getToughness() const
{
  return this->Toughness;
}

void	Droid::setStatus(std::string *newStatus)
{
  if (this->Status)
    delete this->Status;
  this->Status = newStatus;
}

std::string	*Droid::getStatus() const
{
  return this->Status;
}

Droid& Droid::operator=(Droid const & other)
{
  this->Id = other.Id;
  this->Energy = other.Energy;
  delete this->Status;
  this->Status = new std::string(*(other.Status));
  return *this;
}

bool	Droid::operator ==(Droid const& other) const
{
  return *this->Status == *(other.Status);
}

bool	Droid::operator !=(Droid const& other) const
{
  return !(*this == other);
}

Droid&	Droid::operator <<(size_t & energy)
{
  int	tmp;
  if (this->Energy < 100)
    {
      tmp = std::min(100 - this->Energy, energy);
      this->Energy += tmp;
      energy -= tmp;
    }
  return *this;
}

std::ostream & operator <<(std::ostream & os, Droid const & other)
{
  return os << "Droid '" << other.getId() << "', " << *(other.getStatus()) << ", " << other.getEnergy();
}

DroidMemory	*Droid::getBattleData()
{
  return this->BattleData;
}

void		Droid::setBattleData(DroidMemory *newBattleData)
{
  this->BattleData = newBattleData;
}


bool Droid::operator()(std::string const * task, size_t exp)
{
  if (this->Energy <= 10)
    {
      this->Energy = 0;
      setStatus(new std::string("Battery Low"));
      return false;
    }
  this->Energy -= 10;
  std::string *tmp = new std::string(*task);
  if (*(this->BattleData) >= exp)
    {
      *tmp += " - Completed!";
      setStatus(tmp);
      this->BattleData->addExp(exp / 2);
      return true;
    }
  else
    {
      *tmp += " - Failed!";
      setStatus(tmp);
      this->BattleData->addExp(exp);
      return false;
    }
}
