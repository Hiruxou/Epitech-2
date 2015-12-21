//
// ConveyorBeltPepeNoel.hh for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 14:52:48 2015 Nicolas Charvoz
// Last update Sat Jan 17 19:13:13 2015 Nicolas Charvoz
//

#ifndef CONVEYORBELT_HH_
#define CONVEYORBELT_HH_

#include <cstdlib>
#include <string>
#include <iostream>

#include "IConveyorBelt.hh"
#include "Box.hh"
#include "GiftPaper.hh"

class ConveyorBeltPepeNoel : public IConveyorBelt {

private:

  Object *_object;

public:

  ConveyorBeltPepeNoel();

  virtual Object *takeObject();
  virtual void putObject(Object*);
  virtual void pressIN();
  virtual void pressOUT();
  virtual int look() const ;

  virtual IConveyorBelt *createConveyorBelt();

};

#endif
