/*
** Ratatouille.h for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex04
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Jan 22 03:41:03 2015 Nicolas Charvoz
** Last update Thu Jan 22 03:41:04 2015 Nicolas Charvoz
*/

#ifndef __RATATOUILLE_H__
#define	__RATATOUILLE_H__

#include <string>
#include <iostream>
#include <sstream>

class Ratatouille
{
 protected:
  std::stringstream flux;

 public:
  Ratatouille();
  Ratatouille(const Ratatouille & source);
  virtual ~Ratatouille();
  Ratatouille & addVegetable(unsigned char vegetable);
  Ratatouille & addCondiment(unsigned int condiment);
  Ratatouille & addSpice(double spice);
  Ratatouille & addSauce(std::string sauce);
  std::string kooc();
  Ratatouille & operator=(const Ratatouille & source);
};

#endif
