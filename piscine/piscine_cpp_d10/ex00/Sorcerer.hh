//
// Sorcerer.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 10:04:39 2015 Nicolas Charvoz
// Last update Fri Jan 16 11:15:11 2015 Nicolas Charvoz
//

#ifndef SORCERER_HH_
#define SORCERER_HH_

#include <string>
#include <iostream>
#include "Victim.hh"

class Sorcerer {

public:

  Sorcerer(std::string, std::string);
  ~Sorcerer();
  std::string getName();
  std::string getTitle();
  void polymorph(Victim const&) const;

private:
  std::string _name;
  std::string _title;

};

  std::ostream &operator<<(std::ostream&, Sorcerer&);

#endif
