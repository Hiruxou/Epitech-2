/*
** Buzz.h for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex02
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 19 11:14:27 2015 Nicolas Charvoz
** Last update Mon Jan 19 15:13:19 2015 Nicolas Charvoz
*/

#ifndef BUZZ_H_
#define BUZZ_H_

#include "Toy.h"

class Buzz : public Toy {

public:
  Buzz(std::string const&, std::string const &file = "");
  virtual void speak(std::string const &);
  virtual bool speak_es(std::string const &);

};

#endif
