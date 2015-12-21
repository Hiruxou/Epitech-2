//
// Box.cpp for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 10:38:45 2015 Nicolas Charvoz
// Last update Sun Jan 18 00:18:02 2015 Nicolas Charvoz
//

#include "Box.hh"

Box::Box(std::string const &name) : Wrap(name, BOX)
{
}

Box::Box(Box const &b) : Wrap(b._name, b._type)
{
}

Box::~Box()
{
}

void Box::wrapMeThat(Object *o)
{
  if (_isOpen && _content == NULL && o) {
    _content = o;
    std::cout << "[Elf boxing up the gift] : *tuuuut tuuut tuut*" <<std::endl;
  }
  else
    {
      if (!_isOpen)
  	std::cerr << "\033[31m\033[1m[Elf boxing up the gift] : Cannot Wrap : I'm not opened ! \033[0m"
  		  <<std::endl;
      else if (_content)
  	std::cerr << "\033[31m\033[1m[Elf boxing up the gift] : Cannot Wrap : I'm not empty !\033[0m"
  		  <<std::endl;
      else
  	std::cerr << "\033[31m\033[1m[Elf boxing up the gift] : Cannot Wrap : You are dumb !\033[0m"
  		  << std::endl;
    }
}
