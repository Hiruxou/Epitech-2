//
// carrier.hh for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:37:08 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:37:10 2015 Nicolas Charvoz
//

#ifndef CARRIER_HH__
#define CARRIER_HH__

#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include "droid.hh"

class	Carrier
{
  std::string	Id;
  size_t	Energy;
  size_t const	Attack;
  size_t const	Toughness;
  size_t	Speed;
  Droid	**droids;
  Carrier(Carrier const &other);
  Carrier&	operator=(Carrier const &other);
public:
  Carrier(std::string);
  ~Carrier();
  size_t	getEnergy() const;
  void		setEnergy(size_t);
  Carrier&	operator<<(Droid *&droid);
  Carrier&	operator>>(Droid *&droid);
  Droid *&	operator[](int position) const;
  size_t	getSpeed() const;
  size_t	getNbDroid() const;
  Carrier&	operator~();
  bool		operator()(int, int);
  Carrier&	operator<<(size_t& energy);
  std::string		getId() const;
};
std::ostream&	operator<<(std::ostream &os, Carrier const &carrier);
#endif
