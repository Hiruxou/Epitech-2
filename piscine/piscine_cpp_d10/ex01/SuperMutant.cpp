//
// SuperMutant.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 14:55:28 2015 Nicolas Charvoz
// Last update Fri Jan 16 15:00:53 2015 Nicolas Charvoz
//

#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy (170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
  std::cout << "Aaargh ..." <<std::endl;
}

void SuperMutant::takeDamage(int damage)
{
  AEnemy::takeDamage(damage - 3);
}
