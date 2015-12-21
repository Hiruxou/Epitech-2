//
// TablePepeNoel.hh for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 15:52:51 2015 Nicolas Charvoz
// Last update Sat Jan 17 22:45:38 2015 Nicolas Charvoz
//

#ifndef TABLEPEPENOEL_HH_
#define TABLEPEPENOEL_HH_

#include "Teddy.hh"
#include "LittlePony.hh"
#include "ITable.hh"
#include "ConveyorBeltPepeNoel.hh"

class TablePepeNoel : public ITable {

private:

  Object **_objectOnTable;
  int _size;

public:

  TablePepeNoel();
  virtual ~TablePepeNoel();
  virtual void putObject(Object*);
  virtual Object *takeObject(int);
  virtual int *look() const;
  virtual ITable *createTable();

  Object *getObjectOnTable(int) const;
  void reorganize();
};

#endif
