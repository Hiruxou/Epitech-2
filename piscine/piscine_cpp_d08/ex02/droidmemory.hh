//
// droidmemory.hh for  in /home/nicolaschr/rendu/piscine_cpp_d08/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 15 09:41:51 2015 Nicolas Charvoz
// Last update Thu Jan 15 09:41:53 2015 Nicolas Charvoz
//

#ifndef _DROIDMEMORY_HH_
# define _DROIDMEMORY_HH_

# include <string>
# include <iostream>
# include <cstdlib>

class	DroidMemory
{
private:
  size_t fingerPrint;
  size_t Exp;

public:
  DroidMemory();
  ~DroidMemory();

  size_t getFingerPrint() const;
  void setFingerPrint(size_t fingerPrint);
  size_t getExp() const;
  void setExp(size_t exp);
  void addExp(size_t exp);

  DroidMemory & operator<<(DroidMemory const & memory);
  DroidMemory const & operator>>(DroidMemory & memory) const;
  DroidMemory & operator+=(DroidMemory const & memory);
  DroidMemory & operator+=(size_t exp);
  DroidMemory & operator+(DroidMemory const & memory) const;
  DroidMemory & operator+(size_t exp) const;

  bool operator==(DroidMemory const & memory) const;
  bool operator!=(DroidMemory const & memory) const;
  bool operator<(DroidMemory const & memory) const;
  bool operator<=(DroidMemory const & memory) const;
  bool operator>(DroidMemory const & memory) const;
  bool operator>=(DroidMemory const & memory) const;
  bool operator<(size_t memory) const;
  bool operator<=(size_t memory) const;
  bool operator>(size_t memory) const;
  bool operator>=(size_t memory) const;

private:
  static void do_op(DroidMemory &dest, DroidMemory const &memory1, DroidMemory const &memory2);
};

std::ostream & operator<<(std::ostream & os, DroidMemory const & memory);

#endif
