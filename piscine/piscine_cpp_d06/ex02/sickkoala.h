/*
** sickkoala.h for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex02
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 12 11:29:34 2015 Nicolas Charvoz
** Last update Mon Jan 12 13:53:11 2015 Nicolas Charvoz
*/

#ifndef _SICKKOALA_H_
#define _SICKKOALA_H_

#include <string>

class SickKoala {
 private :
  std::string name;

 public:
  SickKoala(std::string);
  ~SickKoala();
  void poke();
  bool takeDrug(std::string);
  void overDrive(std::string);
};

#endif
