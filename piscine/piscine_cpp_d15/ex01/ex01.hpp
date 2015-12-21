//
// ex01.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex01
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 19:45:06 2015 Nicolas Charvoz
// Last update Tue Jan 20 19:54:30 2015 Nicolas Charvoz
//

#ifndef EX01_HPP_
#define EX01_HPP_

#include <cstring>
#include <string>
#include <iostream>

template <typename X>
int compare(const X& a, const X& b)
{
  if (a == b)
    return 0;
  else if (a < b)
    return -1;
  return 1;
}

template <>
int compare<const char*>(const char *const &a, const char *const &b)
{
  int res = strcmp(a,b);

  if (res < 0)
    return -1;
  else if (res > 0)
    return 1;
  return 0;
}

#endif
