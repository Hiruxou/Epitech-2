/*
** Banana.h for  in /home/nicolaschr/rendu/piscine_cpp_d14m/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Jan 20 10:26:57 2015 Nicolas Charvoz
** Last update Tue Jan 20 10:30:52 2015 Nicolas Charvoz
*/

#ifndef BANANA_H_
#define BANANA_H_

#include "Fruit.h"

class Banana : public Fruit {

 public:

  Banana();
  virtual int getVitamins() const;
  virtual std::string const &getName() const;

};

#endif
