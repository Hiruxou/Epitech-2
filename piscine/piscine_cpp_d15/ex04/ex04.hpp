//
// ex04.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex04
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 20:19:25 2015 Nicolas Charvoz
// Last update Tue Jan 20 20:24:59 2015 Nicolas Charvoz
//

#ifndef EX04_HPP_
#define EX04_HPP_

#include <string>
#include <iostream>

template <typename T>
bool equal(const T &a, const T &b);

template <typename T>
class Tester {
protected:

public:
  bool equal(const T &a, const T& b);
};

#endif
