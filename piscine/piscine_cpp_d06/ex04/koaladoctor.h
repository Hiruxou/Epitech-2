/*
** koaladoctor.h for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex04
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 12 15:22:02 2015 Nicolas Charvoz
** Last update Mon Jan 12 16:09:54 2015 Nicolas Charvoz
*/

#ifndef _KOALADOCTOR_H_
#define _KOALADOCTOR_H_

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "sickkoala.h"
#include "koalanurse.h"

class KoalaDoctor {

 private:
  std::string name;
 public:
  KoalaDoctor(std::string);
  ~KoalaDoctor();
  void diagnose(SickKoala*);
  void timeCheck();
};

#endif
