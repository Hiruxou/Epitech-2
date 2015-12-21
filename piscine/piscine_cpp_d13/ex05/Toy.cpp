//
// Toy.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 19 10:05:49 2015 Nicolas Charvoz
// Last update Mon Jan 19 15:56:03 2015 Nicolas Charvoz
//

#include "Toy.h"

Toy::Toy() : _type(BASIC_TOY), _name("toy"), _picture(){}

Toy::Error::Error() : type(UNKNOWN) {}

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
    {
      _error.type = Error::PICTURE;
      return false;
    }
  return true;
}

std::string const &Toy::getAscii() const {
  return _picture.data;
}

void Toy::speak(std::string const &statement)
{
  std::cout << _name << " \"" << statement << "\""<<std::endl;
}

bool Toy::speak_es(std::string const &statement)
{
  (void)statement;
  _error.type = Error::SPEAK;
  return false;
}

std::ostream &operator<<(std::ostream &os, Toy const &toy)
{
  os << toy.getName() << std::endl;
  os << toy.getAscii() << std::endl;

  return os;
}

Toy &Toy::operator<<(std::string const &string)
{
  _picture.data = string;
  return *this;
}

std::string Toy::Error::what() const
{
  if (type == SPEAK)
    return "wrong monde";
  else if (type == PICTURE)
    return "bad new illustration";
  else
    return "";
}

std::string Toy::Error::where() const
{
  if (type == SPEAK)
    return "speak_es";
  else if (type == PICTURE)
    return "setAscii";
  else
    return "";
}

Toy::Error const &Toy::getLastError() const
{
  return _error;
}
