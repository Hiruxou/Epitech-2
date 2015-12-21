//
// Toy.h for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 19 09:49:54 2015 Nicolas Charvoz
//

#ifndef TOY_H_
#define TOY_H_

#include <string>
#include <iostream>
#include "Picture.h"

class Toy {

 public:

  enum	ToyType {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  };

  Toy();
  Toy(Toy const&);
  Toy &operator=(Toy const&);
  Toy(ToyType type, std::string const &name
      , std::string const &picture);
  ToyType getType() const;
  std::string const &getName() const;
  void setName(std::string const&);
  bool setAscii(const std::string &);
  std::string const &getAscii() const;

private:

  ToyType _type;
  std::string _name;
  Picture _picture;

};

#endif
