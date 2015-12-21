//
// Warpsystem.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 09:44:08 2015 Nicolas Charvoz
// Last update Tue Jan 13 09:59:50 2015 Nicolas Charvoz
//

#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor(bool stability)
{
  this->_stability = stability;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
  return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
  this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *core)
{
  this->_coreReactor = core;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
  return this->_coreReactor;
}
