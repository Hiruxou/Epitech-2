//
// Skat.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d07a/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 16:36:34 2015 Nicolas Charvoz
// Last update Tue Jan 13 20:13:27 2015 Nicolas Charvoz
//

#include "Skat.h"

Skat::Skat(std::string const& name, int stimPaks)
{
  this->_name = name;
  this->_stimPaks = stimPaks;
}

Skat::Skat(int stimPaks)
{
  this->_name = "bob";
  this->_stimPaks = stimPaks;
}

Skat::Skat(std::string const& name)
{
  this->_name = name;
  this->_stimPaks = 15;
}

Skat::Skat()
{
  this->_name = "bob";
  this->_stimPaks = 15;
}

Skat::~Skat()
{
}

int& Skat::stimPaks()
{
  return _stimPaks;
}

std::string const& Skat::name()
{
  return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
  if (number <= _stimPaks) {
    stock += number;
    _stimPaks -= number;
    std::cout << "Keep the change." << std::endl;
  }
  else {
    std::cout << "Don't be greedy" << std::endl;
  }
}

void Skat::addStimPaks(unsigned int number) {
  if (!_stimPaks) {
    std::cout << "Hey boya, did you forget something ?" << std::endl;
  }
  _stimPaks += number;
}

void Skat::useStimPaks() {
  if (_stimPaks > 0) {
    _stimPaks--;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
  }
  else {
    std::cout << "Mediiiiiic" << std::endl;
  }
}

void Skat::status() {
  std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir !" << std::endl;
}
