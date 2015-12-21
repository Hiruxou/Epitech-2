//
// DomesticKoala.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Jan 21 20:40:07 2015 Nicolas Charvoz
// Last update Wed Jan 21 20:40:08 2015 Nicolas Charvoz
//

#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction& action): _action(action), _knowAction(256)
{
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(DomesticKoala const& other): _action(other._action), _knowAction(other._knowAction)
{
}

DomesticKoala& DomesticKoala::operator=(DomesticKoala const& other)
{
  _action = other._action;
  _knowAction = other._knowAction;
  return *this;
}

std::vector<DomesticKoala::methodPointer_t> const* DomesticKoala::getActions() const
{
  return &_knowAction;
}

void DomesticKoala::learnAction(unsigned char c, methodPointer_t ptr)
{
  _knowAction[c] = ptr;
}

void DomesticKoala::unlearnAction(unsigned char c)
{
  _knowAction[c] = NULL;
}

void DomesticKoala::doAction(unsigned char c, std::string const& str)
{
  methodPointer_t func = _knowAction[c];

  if (func)
    (_action.*func)(str);
}

void DomesticKoala::setKoalaAction(KoalaAction& action)
{
  _action = action;
}
