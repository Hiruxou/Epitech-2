//
// Character.hh for  in /home/nicolaschr/rendu/piscine_cpp_d09/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 10:54:50 2015 Nicolas Charvoz
// Last update Thu Jan 15 17:44:34 2015 Nicolas Charvoz
//


#ifndef CHARACTER_HH_
#define CHARACTER_HH_

#include <string>
#include <iostream>

typedef enum e_AttackRange {
    A_RANGE,
    A_CLOSE
  } AttackRange;

class Character  {

protected:

  std::string _name;
  int _level;
  int _pV;
  int _power;
  int _strength;
  int _stamina;
  int _intelligence;
  int _spirit;
  int _agility;
  std::string _race;

public:

  AttackRange Range;

public:

  Character(const std::string&, int);
  virtual ~Character();
  const std::string& getName() const;
  int getLvl() const;
  int getPv() const;
  int getPower() const;
  int CloseAttack();
  int RangeAttack();
  void Heal();
  void RestorePower();
  void TakeDamage(int);
  const static AttackRange RANGE = A_RANGE;
  const static AttackRange CLOSE = A_CLOSE;
};

#endif
