//
// Object.cpp for Object in /home/garcia_t/cpp_santa
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Jan 17 09:37:54 2015 antoine garcia
// Last update Sat Jan 17 23:05:40 2015 Nicolas Charvoz
//

#include "Object.hh"

Object::Object(std::string const &name, int type):_name(name),_type(type)
{
}

Object::Object(Object const & other):_name(other._name), _type(other._type)
{}

Object&	Object::operator=(Object const &other)
{
  _name = other._name;
  _type = other._type;
  return *this;
}

std::string const &Object::getName() const
{
  return _name;
}

int Object::getType() const
{
  return _type;
}
