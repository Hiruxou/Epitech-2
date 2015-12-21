//
// droid.hh for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:40:12 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:40:13 2015 Nicolas Charvoz
//

#ifndef DROID_HH_
#define DROID_HH_

#include <string>
#include <iostream>
#include <algorithm>
#include "droidmemory.hh"

class				Droid
{
private:
  std::string			id;
  size_t			energy;
  size_t const			attack;
  size_t const			toughness;
  std::string			*status;
  DroidMemory			*battleData;
  void output(std::string message);

public:
  Droid(std::string id);
  Droid(Droid const & droid);
  ~Droid();
  std::string			getId() const;
  size_t			getEnergy() const;
  size_t			getAttack() const;
  size_t			getToughness() const;
  std::string*			getStatus() const;
  DroidMemory*			getBattleData() const;
  void				setId(std::string id);
  void				setEnergy(size_t energy);
  void				setStatus(std::string *status);
  void				setBattleData(DroidMemory *memory);
  Droid&			operator=(Droid const & droid);
  bool				operator==(Droid const & droid) const;
  bool				operator!=(Droid const & droid) const;
  Droid&			operator<<(size_t & energy);

};

std::ostream &			operator<<(std::ostream & os, Droid const & droid);

#endif /* !DROID_HH_ */
