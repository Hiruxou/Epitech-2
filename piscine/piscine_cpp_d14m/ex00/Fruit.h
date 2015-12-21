/*
** Fruit.h for  in /home/nicolaschr/rendu/piscine_cpp_d14m/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Jan 20 09:57:41 2015 Nicolas Charvoz
** Last update Tue Jan 20 10:33:41 2015 Nicolas Charvoz
*/

#ifndef FRUIT_H_
#define FRUIT_H_

#include <string>
#include <iostream>

class Fruit {

public:

  Fruit(std::string const&, int);
  Fruit(Fruit const&);
  virtual ~Fruit();
  virtual int getVitamins() const = 0;
  virtual std::string const &getName() const = 0;

protected:

  std::string _name;
  int _vitamins;


};

#endif
