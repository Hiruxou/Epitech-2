//
// ElfOfPepeNoel.hh for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 21:06:44 2015 Nicolas Charvoz
// Last update Sat Jan 17 22:47:05 2015 Nicolas Charvoz
//

#ifndef ELFOFPEPENOEL_HH_
#define ELFOFPEPENOEL_HH_

#include "IElf.hh"

class ElfOfPepeNoel : public IElf {
private:

public:

  ElfOfPepeNoel();
  ~ElfOfPepeNoel();

  virtual void makeGift(TablePepeNoel &, ConveyorBeltPepeNoel const&);

};

#endif
