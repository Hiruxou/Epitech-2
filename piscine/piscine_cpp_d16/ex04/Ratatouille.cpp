//
// Ratatouille.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex04
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 22 03:40:52 2015 Nicolas Charvoz
// Last update Thu Jan 22 03:40:56 2015 Nicolas Charvoz
//

#include "Ratatouille.h"

Ratatouille::Ratatouille()
{
}

Ratatouille::Ratatouille(const Ratatouille &src)
{
  flux.str("");
  flux << src.flux.rdbuf();
}

Ratatouille::~Ratatouille()
{
}

Ratatouille& Ratatouille::addVegetable(unsigned char vegetable)
{
  flux << vegetable;
  return *this;
}

Ratatouille&  Ratatouille::addCondiment(unsigned int condiment)
{
  flux << condiment;
  return *this;
}

Ratatouille& Ratatouille::addSpice(double spice)
{
  flux << spice;
  return *this;
}

Ratatouille& Ratatouille::addSauce(std::string sauce)
{
  flux << sauce;
  return *this;
}

std::string Ratatouille::kooc()
{
  return flux.str();
}

Ratatouille& Ratatouille::operator=(const Ratatouille& source)
{
  flux.str("");
  flux << source.flux.rdbuf();
  return *this;
}
