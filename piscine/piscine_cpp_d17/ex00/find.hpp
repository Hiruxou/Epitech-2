//
// find.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d17/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 22 05:09:11 2015 Nicolas Charvoz
// Last update Thu Jan 22 05:11:54 2015 Nicolas Charvoz
//

#ifndef FIND_HPP_
#define FIND_HPP_

#include <string>
#include <iostream>
#include <algorithm>

template <typename T>

typename T::iterator  do_find(const T &t, int i)
{
  return std::find(t.begin(), t.end(), i);
}

#endif
