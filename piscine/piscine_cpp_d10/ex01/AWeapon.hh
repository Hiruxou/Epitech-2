//
// AWeapon.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 11:30:57 2015 Nicolas Charvoz
// Last update Fri Jan 16 16:11:27 2015 Nicolas Charvoz
//

#ifndef AWEAPON_HH_
#define AWEAPON_HH_

#include <string>
#include <iostream>

class AWeapon {

private:
  std::string _name;
  int _apcost;
  int _damage;


  public:
  AWeapon(std::string const &name, int apcost, int damage);
  virtual ~AWeapon();
  std::string const &getName() const;
  int getAPCost() const;
  int getDamage() const;
  virtual void attack() const = 0;

};

#endif
