//
// Character.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 15:21:29 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:04:27 2015 Nicolas Charvoz
//

#ifndef CHARACTER_HH_
#define CHARACTER_HH_

#include <string>
#include <iostream>

#include "AWeapon.hh"
#include "AEnemy.hh"

class Character  {

private:

  std::string _name;
  int _ap;
  AWeapon *_currentWeapon;

public:

  Character(std::string const &name);
  ~Character();
  bool action(int);
  std::string const &getName() const;
  int getAP() const;
  AWeapon *getWeapon() const;
  void recoverAP();
  void equip(AWeapon*);
  void attack(AEnemy*);

};

std::ostream &operator<<(std::ostream &, Character const &);

#endif
