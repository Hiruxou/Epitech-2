//
// droidmemory.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:41:41 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:41:43 2015 Nicolas Charvoz
//

#include "droidmemory.hh"


DroidMemory::DroidMemory():Exp(0)
{
  this->fingerPrint = random();
}

DroidMemory::~DroidMemory()
{

}

size_t DroidMemory::getFingerPrint() const
{
  return this->fingerPrint;
}

void DroidMemory::setFingerPrint(size_t fingerPrint)
{
  this->fingerPrint = fingerPrint;
}

size_t DroidMemory::getExp() const
{
  return this->Exp;
}

void DroidMemory::setExp(size_t exp)
{
  this->Exp = exp;
}

void DroidMemory::addExp(size_t exp)
{
  this->Exp += exp;
}

DroidMemory & DroidMemory::operator <<(DroidMemory const & memory)
{
  DroidMemory::do_op(*this, *this, memory);
  return *this;
}

DroidMemory const & DroidMemory::operator >>(DroidMemory & memory) const
{
  DroidMemory::do_op(memory, *this, memory);
  return *this;
}

DroidMemory & DroidMemory::operator +=(DroidMemory const & memory)
{
  DroidMemory::do_op(*this, *this, memory);
  return *this;
}

DroidMemory & DroidMemory::operator +=(size_t exp)
{
  DroidMemory memory;
  memory.Exp = exp;
  memory.fingerPrint = exp;
  DroidMemory::do_op(*this, *this, memory);
  return *this;
}

DroidMemory & DroidMemory::operator +(DroidMemory const & memory) const
{
  DroidMemory *tmp = new DroidMemory();
  DroidMemory::do_op(*tmp, *this, memory);
  return *tmp;
}

DroidMemory & DroidMemory::operator +(size_t exp) const
{
  DroidMemory memory;
  memory.Exp = exp;
  memory.fingerPrint = exp;
  DroidMemory *tmp = new DroidMemory();
  DroidMemory::do_op(*tmp, *this, memory);
  return *tmp;
}

bool	DroidMemory::operator ==(DroidMemory const & memory) const
{
  return this->Exp == memory.Exp && this->fingerPrint == memory.fingerPrint;
}

bool	DroidMemory::operator !=(DroidMemory const & memory) const
{
  return !(*this == memory);
}

bool	DroidMemory::operator <(DroidMemory const & memory) const
{
  return this->Exp < memory.Exp;
}

bool	DroidMemory::operator <=(DroidMemory const & memory) const
{
  return this->Exp <= memory.Exp;
}

bool	DroidMemory::operator >(DroidMemory const & memory) const
{
  return this->Exp > memory.Exp;
}

bool	DroidMemory::operator >=(DroidMemory const & memory) const
{
  return this->Exp >= memory.Exp;
}

bool	DroidMemory::operator <(size_t memory) const
{
  return this->Exp < memory;
}

bool	DroidMemory::operator <=(size_t memory) const
{
  return this->Exp <= memory;
}

bool	DroidMemory::operator >(size_t memory) const
{
  return this->Exp > memory;
}

bool	DroidMemory::operator >=(size_t memory) const
{
  return this->Exp >= memory;
}

void	DroidMemory::do_op(DroidMemory &dest, DroidMemory const &memory1, DroidMemory const &memory2)
{
  dest.Exp = memory1.Exp + memory2.Exp;
  dest.fingerPrint = memory1.fingerPrint ^ memory2.fingerPrint;
}

std::ostream & operator <<(std::ostream & os, DroidMemory const & memory)
{
  return os << "DroidMemory '" << memory.getFingerPrint() << "', " << memory.getExp();
}
