//
// TablePepeNoel.cpp for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 15:55:48 2015 Nicolas Charvoz
// Last update Sun Jan 18 00:21:49 2015 Nicolas Charvoz
//

#include "TablePepeNoel.hh"

TablePepeNoel::TablePepeNoel()
{
  _objectOnTable = new Object *[10];

  for (int i = 0; i < 10; i++) {
    _objectOnTable[i] = NULL;
  }
  _size = 10;
}

TablePepeNoel::~TablePepeNoel()
{
  for (int i = 0; i < 10 ; i++) {
    _objectOnTable[i] = NULL;
    delete _objectOnTable[i];
  }
  delete _objectOnTable;
}

void TablePepeNoel::putObject(Object *o)
{
  int i = 0;

  while (i < _size) {
    if (_objectOnTable[i] == NULL)
      _objectOnTable[i] = o;
    i++;
  }
}

Object *TablePepeNoel::takeObject(int type)
{
  int i = 0;
  Object *newObj = new Object;

  while (_objectOnTable[i])
    {
      if (_objectOnTable[i]->getType() == type) {
	newObj = _objectOnTable[i];
	_objectOnTable[i] = NULL;
      }
      i++;
    }
  _size -= 1;
  return newObj;
}

int *TablePepeNoel::look() const
{
  int *tableContent = new int[10];
  int i = 0;

  while (i < _size)
    {
      tableContent[i] = _objectOnTable[i]->getType();
      if (tableContent[i] == LITTLEPONY)
	std::cout << "\033[34m[Room - " << i + 1
		  << "] Little Pony named "
		  << _objectOnTable[i]->getName() << std::endl;
      else if (tableContent[i] == TEDDY)
	std::cout << "\033[34m[Room - " << i + 1
		  << "] Teddy named "
		  << _objectOnTable[i]->getName() << std::endl;

      else if (tableContent[i] == BOX)
	std::cout << "\033[34m[Room - " << i + 1
		  << "] Box" << std::endl;

      else if (tableContent[i] == GIFTPAPER)
	std::cout << "\033[34m[Room - " << i + 1
		  << "] GiftPaper" << std::endl;
      i++;
    }
  return tableContent;
}

void TablePepeNoel::reorganize()
{
  int i;
  int j = 0;

  for (i = 0; i < _size; i++) {
    if (_objectOnTable[i]) {
      _objectOnTable[i] = _objectOnTable[j];
      j++;
    }
  }
  for (; j < _size ; j++) {
    _objectOnTable[j] = NULL;
  }
}

ITable *TablePepeNoel::createTable()
{
  ITable *newObj = new TablePepeNoel;

  _objectOnTable[0] = new Teddy("Riner");
  _objectOnTable[1] = new LittlePony("Couillere");
  _objectOnTable[2] = new Box;
  _objectOnTable[3] = new Box;
  _objectOnTable[4] = new GiftPaper;
  _objectOnTable[5] = new GiftPaper;
  _objectOnTable[6] = new Teddy("Teddy");
  _objectOnTable[7] = new Box;
  _objectOnTable[8] = new GiftPaper;
  _objectOnTable[9] = new Box;
  _objectOnTable[10] = NULL;

  return newObj;
}

Object *TablePepeNoel::getObjectOnTable(int i) const
{
  return _objectOnTable[i];
}
