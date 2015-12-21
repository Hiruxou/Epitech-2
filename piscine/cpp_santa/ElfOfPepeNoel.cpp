//
// ElfOfPepeNoel.cpp for  in /home/nicolaschr/rendu/cpp_santa
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Jan 17 21:10:05 2015 Nicolas Charvoz
// Last update Sun Jan 18 00:21:59 2015 Nicolas Charvoz
//

#include "ElfOfPepeNoel.hh"

ElfOfPepeNoel::ElfOfPepeNoel() {
  std::cout << "[Elf] : Hey I'm an Elf and I'm ready to wrap some gifts"
	    << std::endl;
}

ElfOfPepeNoel::~ElfOfPepeNoel() {
  std::cout << "[Elf] : I don't have toys to wrap anymore. I have finished my job " << std::endl;
}

void ElfOfPepeNoel::makeGift(TablePepeNoel & table, ConveyorBeltPepeNoel const &conveyor) {
  (void)conveyor;

  table.look();
  int numberOfGift = 1;

  // Gift 1
  ((Wrap *)table.getObjectOnTable(2))->openMe();
  if (((Wrap *)table.getObjectOnTable(2))->getIsOpen() == true)
    std::cout << "\033[0m[Elf] : I opened the box \033[0m" << std::endl;
  ((Wrap *)table.getObjectOnTable(2))->wrapMeThat(table.getObjectOnTable(1));
  if (((Wrap *)table.getObjectOnTable(2))->getIsOpen() == true)
    std::cout << "[Elf] : I put the toy named " << table.getObjectOnTable(0)->getName()
	      << " in the box" << std::endl;
  ((Wrap *)table.getObjectOnTable(2))->closeMe();
  if (((Wrap *)table.getObjectOnTable(2))->getIsOpen() == false)
    std::cout << "[Elf] : I closed the box" << std::endl;
  std::cout << "[Elf] : whistles while working" << std::endl;
  ((Wrap *)table.getObjectOnTable(5))->wrapMeThat(table.getObjectOnTable(3));
  std::cout << "\033[32m\033[1m[Elf] : I sent the gift to Santa Claus ! ["
	     << numberOfGift << "]\033[0m" << std::endl;
  numberOfGift++;

  //Gift 2
  ((Wrap *)table.getObjectOnTable(3))->openMe();
  if (((Wrap *)table.getObjectOnTable(3))->getIsOpen() == true)
    std::cout << "[Elf] : I opened the box" << std::endl;
  ((Wrap *)table.getObjectOnTable(3))->wrapMeThat(table.getObjectOnTable(0));
  if (((Wrap *)table.getObjectOnTable(3))->getIsOpen() == true)
    std::cout << "[Elf] : I put the toy named " << table.getObjectOnTable(0)->getName()
	      << " in the box" << std::endl;
  ((Wrap *)table.getObjectOnTable(3))->closeMe();
  if (((Wrap *)table.getObjectOnTable(3))->getIsOpen() == false)
    std::cout << "[Elf] : I closed the box" << std::endl;
  std::cout << "[Elf] : whistles while working" << std::endl;
  ((Wrap *)table.getObjectOnTable(4))->wrapMeThat(table.getObjectOnTable(3));
  std::cout << "\033[32m[\033[1mElf] : I sent the gift to Santa Claus ! ["
	    << numberOfGift << "]\033[0m" << std::endl;
  numberOfGift++;

  //Gift 3
  if (((Wrap *)table.getObjectOnTable(3))->getIsOpen() == true)
    std::cout << "[Elf] : I opened the box" << std::endl;
  ((Wrap *)table.getObjectOnTable(3))->wrapMeThat(table.getObjectOnTable(0));


}
