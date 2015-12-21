/*
** ToyStory.h for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex06
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 19 15:58:45 2015 Nicolas Charvoz
** Last update Mon Jan 19 16:20:07 2015 Nicolas Charvoz
*/

#ifndef TOYSTORY_H_
#define TOYSTORY_H_

#include <string>
#include <iostream>
#include <fstream>
#include "Toy.h"

typedef bool (Toy::*toy_speak)(std::string const &message);

class ToyStory {

 public:
  ToyStory();
  ~ToyStory();

  static bool tellMeAStory(std::string const &filename, Toy &toy1, toy_speak speak1, Toy &toy2, toy_speak speak2);


};

#endif
