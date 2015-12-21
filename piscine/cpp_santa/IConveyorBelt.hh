//
// IConveyorBelt.hh for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 13:36:15 2015 Nicolas Charvoz
// Last update Sat Jan 17 19:18:11 2015 Nicolas Charvoz
//

#ifndef ICONVEYORBELT_HH_
#define ICONVEYORBELT_HH_

#include <string>
#include <iostream>
#include "Object.hh"
#include "Wrap.hh"

class IConveyorBelt {

public:
  virtual ~IConveyorBelt() {}

  virtual Object *takeObject() = 0;
  virtual void putObject(Object*) = 0;
  virtual void pressIN() = 0;
  virtual void pressOUT()  = 0;
  virtual int look() const = 0;
  virtual IConveyorBelt *createConveyorBelt() = 0;

};

#endif
