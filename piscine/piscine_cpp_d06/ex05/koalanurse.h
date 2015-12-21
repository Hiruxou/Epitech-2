/*
** koalanurse.h for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex03
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 12 13:51:43 2015 Nicolas Charvoz
** Last update Mon Jan 12 16:16:30 2015 Nicolas Charvoz
*/

#ifndef _KOALANURSE_H_
#define _KOALANURSE_H_


#include <string>
#include <iostream>
#include "sickkoala.h"

class KoalaNurse {
 private:
  int id;

 public:
  KoalaNurse(int);
  ~KoalaNurse();
  void giveDrug(std::string, SickKoala*);
  std::string readReport(std::string);
  void timeCheck();
  int getID();
};

#endif
