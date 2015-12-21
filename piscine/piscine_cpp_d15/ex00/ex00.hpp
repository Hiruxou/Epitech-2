//
// ex00.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 19:36:06 2015 Nicolas Charvoz
// Last update Tue Jan 20 19:42:21 2015 Nicolas Charvoz
//

#ifndef EX00_HPP_
#define EX00_HPP_

#include <string>
#include <iostream>

template <typename X>
void swap(X& a, X& b)
{
  X c = a;
  a = b;
  b = c;
}

template <typename X>
X min(X a, X b)
{
  if (a < b)
    return a;
  return b;
}

template <typename X>
X max(X a, X b)
{
  if (a > b)
    return a;
  return b;
}

template <typename X>
X add(const X& a, const X& b)
{
  return a + b;
}

#endif
