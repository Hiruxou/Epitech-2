//
// main.cpp for main in /home/garcia_t/cpp_santa
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Jan 17 10:19:51 2015 antoine garcia
// Last update Sun Jan 18 10:12:43 2015 Nicolas Charvoz
//

#include "Toy.hh"
#include "LittlePony.hh"
#include "Teddy.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include "ElfOfPepeNoel.hh"
#include "TablePepeNoel.hh"
#include "ConveyorBeltPepeNoel.hh"

Object	**MyUnitTests()
{
  Object	**test = new Object*[2];
  test[0] = new Teddy("bisounours");
  test[1] = new LittlePony("gay pony");

  return test;
}

Object	*MyUnitTest2(Object ** test2)
{
  ((Wrap *)test2[1])->openMe();
  ((Wrap *)test2[1])->wrapMeThat(test2[0]);
  ((Wrap *)test2[2])->wrapMeThat(test2[1]);
  ((Wrap *)test2[2])->wrapMeThat(test2[1]);
  return test2[0];
}

int	main()
{
  // Object **test = new Object *[4];
  // test[0] = new Teddy("bisous");
  // test[1] = new Box("box");
  // test[2] = new GiftPaper("giftor");
  // Object *test1 = MyUnitTest2(test);
  // (void) test;
  // (void) test1;

  TablePepeNoel table;
  ConveyorBeltPepeNoel conveyor;
  ElfOfPepeNoel elf;

  table.createTable();
  elf.makeGift(table, conveyor);
  return 0;
}
