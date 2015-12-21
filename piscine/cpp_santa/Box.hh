//
// Box.hh for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 10:38:46 2015 Nicolas Charvoz
// Last update Sat Jan 17 13:13:32 2015 Nicolas Charvoz
//

#ifndef BOX_HH_
#define BOX_HH_

#include <string>
#include <iostream>

#include "Wrap.hh"

class Box : public Wrap {
public:

  Box(std::string const &name = "");
  Box(Box const&);
  ~Box();
  virtual void wrapMeThat(Object *);

private:

};

#endif
