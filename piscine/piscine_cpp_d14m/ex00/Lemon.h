/*
** Lemon.h for  in /home/nicolaschr/rendu/piscine_cpp_d14m/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Jan 20 10:17:19 2015 Nicolas Charvoz
** Last update Tue Jan 20 10:31:01 2015 Nicolas Charvoz
*/

#ifndef LEMON_H_
#define LEMON_H_

#include "Fruit.h"

class Lemon : public Fruit {

 public:
  Lemon();
  virtual int getVitamins() const;
  virtual std::string const &getName() const;

};

#endif
