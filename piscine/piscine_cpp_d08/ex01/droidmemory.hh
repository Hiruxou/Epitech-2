//
// droidmemory.hh for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:40:44 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:40:45 2015 Nicolas Charvoz
//

#ifndef DROIDMEMORY_HH_
#define DROIDMEMORY_HH_

#include <string>
#include <iostream>
#include <cstdlib>

class				DroidMemory
{
private:
  size_t			fingerPrint;
  size_t			exp;
  static void			fusion(DroidMemory &dest, DroidMemory const &memory1, DroidMemory const &memory2);

public:
  DroidMemory();
  ~DroidMemory();
  size_t			getFingerPrint() const;
  size_t			getExp() const;
  void				setFingerPrint(size_t fingerPrint);
  void				setExp(size_t exp);
  DroidMemory &			operator<<(DroidMemory const & memory);
  DroidMemory const &		operator>>(DroidMemory & memory) const;
  DroidMemory &			operator+=(DroidMemory const & memory);
  DroidMemory &			operator+=(size_t exp);
  DroidMemory &			operator+(DroidMemory const & memory) const;
  DroidMemory &			operator+(size_t exp) const;

};

std::ostream &			operator<<(std::ostream & os, DroidMemory const & memory);

#endif /* !DROIDMEMORY_HH_ */
