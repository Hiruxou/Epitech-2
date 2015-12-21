//
// droid.hh for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:41:32 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:41:33 2015 Nicolas Charvoz
//

#ifndef _DROID_HH_
# define _DROID_HH_

# include <string>
# include <iostream>
# include <algorithm>
# include "droidmemory.hh"

class	Droid
{
private:
  std::string	Id;
  size_t	Energy;
  size_t const	Attack;
  size_t const	Toughness;
  std::string	*Status;
  DroidMemory	*BattleData;

public:
  Droid(std::string id);
  Droid(Droid const & droid);
  ~Droid();

  void setId(std::string);
  std::string getId() const;
  void setEnergy(size_t);
  size_t getEnergy() const;
  size_t getAttack() const;
  size_t getToughness() const;
  void setStatus(std::string*);
  std::string *getStatus() const;
  Droid& operator=(Droid const &);
  bool operator ==(Droid const&) const;
  bool operator !=(Droid const&) const;
  Droid& operator <<(size_t &);
  bool operator()(std::string const * task, size_t exp);
  DroidMemory	*getBattleData();
  void setBattleData(DroidMemory *);
};

std::ostream & operator <<(std::ostream & os, Droid const & droid);

#endif
