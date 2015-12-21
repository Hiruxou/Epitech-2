//
// ITable.hh for ITable in /home/garcia_t/cpp_santa
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Jan 17 13:35:44 2015 antoine garcia
// Last update Sat Jan 17 18:58:16 2015 Nicolas Charvoz
//

#ifndef ITABLE_HH_
#define ITABLE_HH_

#include "Object.hh"

class	ITable
{

public:
  virtual	~ITable(){};
  virtual void	putObject(Object *) = 0;
  virtual Object	*takeObject(int) = 0;
  virtual int		*look() const = 0;
  virtual ITable *createTable() = 0;
};

#endif
