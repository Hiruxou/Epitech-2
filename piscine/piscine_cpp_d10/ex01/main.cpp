//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 14:42:13 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:04:53 2015 Nicolas Charvoz
//

#include "Character.hh"
#include "AEnemy.hh"
#include "AWeapon.hh"
#include "PlasmaRifle.hh"
#include "PowerFist.hh"
#include "RadScorpion.hh"
#include "SuperMutant.hh"

int main()
{
  Character* zaz = new Character("zaz");
  std::cout << *zaz;
  AEnemy* b = new RadScorpion();
  AWeapon* pr = new PlasmaRifle();
  AWeapon* pf = new PowerFist();
  zaz->equip(pr);
  std::cout << *zaz;
  zaz->equip(pf);
  zaz->attack(b);
  std::cout << *zaz;
  zaz->equip(pr);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  return 0;
  }
