//
// Toy.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 19 10:05:49 2015 Nicolas Charvoz
// Last update Mon Jan 19 11:11:10 2015 Nicolas Charvoz
//

#include "Toy.h"

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture(){}

Toy::Toy(Toy const &toy)
{
  _type = toy._type;
  _name = toy._name;
  _picture = toy._picture;
}

Toy &Toy::operator=(Toy const &toy)
{
  _type = toy._type;
  _name = toy._name;
  _picture = toy._picture;
  return *this;
}

Toy::Toy(ToyType type, std::string const &name, std::string const &picture) : _type(type), _name(name), _picture(picture)
{
}

Toy::ToyType Toy::getType() const {
  return _type;
}

std::string const &Toy::getName() const {
  return _name;
}

void Toy::setName(std::string const &newName)
{
  _name = newName;
}

bool Toy::setAscii(const std::string &file) {
  if (!_picture.getPictureFromFile(file))
    return false;
  return true;
}

std::string const &Toy::getAscii() const {
  return _picture.data;
}
