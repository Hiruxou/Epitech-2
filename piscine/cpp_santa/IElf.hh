//
// IElf.hh for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 19:18:43 2015 Nicolas Charvoz
// Last update Sat Jan 17 22:46:51 2015 Nicolas Charvoz
//

#ifndef IELF_HH_
#define IELF_HH_

#include <string>
#include <iostream>
#include "ConveyorBeltPepeNoel.hh"
#include "TablePepeNoel.hh"

class IElf {

public:

  virtual ~IElf() {}

  virtual void makeGift(TablePepeNoel &, ConveyorBeltPepeNoel const&) = 0;

};

#endif
