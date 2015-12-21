//
// Toy.hh for Santa in /home/nicolas/rendu/cpp_santa
// 
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
// 
// Started on  Sat Jan 17 09:28:42 2015 Nicolas Girardot
// Last update Sat Jan 17 09:58:09 2015 Nicolas Girardot
//

#ifndef TOY_HH_
#define TOY_HH_

#include "Object.hh"
#include <iostream>

class Toy : public Object
{
public:
  Toy(std::string const &, int);
  Toy(Toy const &);
  ~Toy();
  virtual void	isTaken() const;
};

#endif
