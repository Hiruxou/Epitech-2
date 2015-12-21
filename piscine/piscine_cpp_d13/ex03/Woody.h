/*
** Woody.h for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex02
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 19 12:02:35 2015 Nicolas Charvoz
** Last update Mon Jan 19 12:47:32 2015 Nicolas Charvoz
*/

#ifndef WOODY_H_
#define WOODY_H_

#include <string>
#include <iostream>

#include "Toy.h"

class Woody : public Toy {

 public:
  Woody(std::string const&, std::string const &file = "");
  virtual void speak(std::string const&);
};

#endif
