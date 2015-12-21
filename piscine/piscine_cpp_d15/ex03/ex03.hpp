//
// ex03.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 20:14:33 2015 Nicolas Charvoz
// Last update Tue Jan 20 20:18:06 2015 Nicolas Charvoz
//

#ifndef EX03_HPP_
#define EX03_HPP_

#include <string>
#include <iostream>

template <typename X>
void foreach(const X *tab, void (func)(const X &), int size)
{
  int i = 0;
  while (i < size) {
    (*func)(tab[i]);
    i++;
  }
}
template <typename T>
void print(const T &a) {
  std::cout << a << std::endl;
}

#endif
