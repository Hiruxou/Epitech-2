//
// ex02.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 19:55:21 2015 Nicolas Charvoz
// Last update Tue Jan 20 20:06:36 2015 Nicolas Charvoz
//

#ifndef EX02_HPP_
#define EX02_HPP_

#include <string>
#include <iostream>

int min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (a < b)
    return a;
  else if (a > b)
    return b;
  return a;
}


int nonTemplateMin(int *tab, int size)
{
  int m = tab[0];
  int i = 1;

  while (i < size)
    {
      m = min(m, tab[i]);
      i++;
    }
  return m ;
}

template <typename X>
const X &min(const X& a, const X& b)
{
  std::cout << "template min" << std::endl;
  if (a <= b)
    return a;
  return b;
}

template <typename X>
const X &templateMin(const X *tab, int size)
{
  X &m = const_cast<X&>(tab[0]);
  int i = 1;

  while (i < size)
    {
      m = min<X>(m, tab[i]);
      i++;
    }
  return m;
}


#endif
