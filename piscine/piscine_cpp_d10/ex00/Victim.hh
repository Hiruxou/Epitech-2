//
// Victim.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 10:19:52 2015 Nicolas Charvoz
// Last update Fri Jan 16 11:20:03 2015 Nicolas Charvoz
//

#ifndef VICTIM_HH_
#define VICTIM_HH_

#include <string>
#include <iostream>

class Victim {

public:

  Victim(std::string);
  virtual ~Victim();
  virtual void getPolymorphed() const;
  std::string getName();
protected:

  std::string _name;

};

std::ostream& operator<<(std::ostream&, Victim&);

#endif
