//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex06
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Jan 21 15:50:13 2015 Nicolas Charvoz
// Last update Wed Jan 21 18:23:15 2015 Nicolas Charvoz
//

#include "ex06.hpp"

int		main()
{
  Tuple<float, char> t;
  t.a = 1.1f;
  t.b = 'x';
  std::cout << t.toString() << std::endl;
  return 0;
}
