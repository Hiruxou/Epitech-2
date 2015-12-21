//
// ConveyorBeltPepeNoel.cpp for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 14:59:46 2015 Nicolas Charvoz
// Last update Sat Jan 17 19:15:34 2015 Nicolas Charvoz
//

#include "ConveyorBeltPepeNoel.hh"

ConveyorBeltPepeNoel::ConveyorBeltPepeNoel() : _object(NULL) {}

Object *ConveyorBeltPepeNoel::takeObject() {
  Object *newObj = _object;
  _object = NULL;

  return newObj;
}

void ConveyorBeltPepeNoel::putObject(Object *w) {
  _object = w;
}

void ConveyorBeltPepeNoel::pressIN() {
  if (random() % 2)
    putObject(new Box);
  else
    putObject(new GiftPaper);
}

void ConveyorBeltPepeNoel::pressOUT() {
  _object = NULL;
}

int ConveyorBeltPepeNoel::look() const {
  return _object->getType();
}

IConveyorBelt *ConveyorBeltPepeNoel::createConveyorBelt()
{
  IConveyorBelt *newObj = new ConveyorBeltPepeNoel;
  return newObj;
}
