//
// Wrap.cpp for Wrap in /home/garcia_t/cpp_santa
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Jan 17 10:50:58 2015 antoine garcia
// Last update Sat Jan 17 23:10:37 2015 Nicolas Charvoz
//

#include "Wrap.hh"

Wrap::Wrap(std::string const &name, int type):Object(name, type),_isOpen(false),_content(NULL)
{}

Wrap::~Wrap(){}

Wrap::Wrap(Wrap const & other):Object(other._name, other._type),_isOpen(false),_content(NULL)
{}

Wrap&	Wrap::operator=(Wrap const &other)
{
  *this = other;
  _isOpen = other._isOpen;
  _content = other._content;
  return *this;
}

Object	*Wrap::takeMe()
{
  if (_content != NULL)
    {
      Object *newObj = _content;
      _content = NULL;
      return newObj;
    }
  return NULL;
}

void	Wrap::openMe()
{
  _isOpen = true;
}

void	Wrap::closeMe()
{
  _isOpen = false;
}

bool Wrap::getIsOpen() const
{
  return _isOpen;
}

bool Wrap::getIsWrapped() const
{
  if (_content)
    return true;
  return false;
}
